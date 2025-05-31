#pragma once
#include <string>

class Transaction {
public:
    Transaction();
    bool Make(Account& from, Account& to, double amount);
    void set_fee(double fee);
    double fee() const;
private:
    double fee_;
};
