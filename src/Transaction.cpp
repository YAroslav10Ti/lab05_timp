#include "Transaction.h"

Transaction::Transaction() : fee_(0) {}

bool Transaction::Make(Account& from, Account& to, double amount) {
    if (from.GetId() == to.GetId()) return false;
    if (amount < 0) return false;
    if (from.IsLocked() || to.IsLocked()) return false;
    
    double total = amount + fee_;
    if (from.GetBalance() < total) return false;
    
    from.ChangeBalance(-total);
    to.ChangeBalance(amount);
    return true;
}

void Transaction::set_fee(double fee) { fee_ = fee; }
double Transaction::fee() const { return fee_; }
