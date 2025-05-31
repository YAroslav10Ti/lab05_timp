#include "Account.h"

Account::Account(int id, double balance) 
    : id_(id), balance_(balance), is_locked_(false) {}

int Account::GetId() const { return id_; }
double Account::GetBalance() const { return balance_; }
bool Account::IsLocked() const { return is_locked_; }

void Account::ChangeBalance(double diff) {
    if (!is_locked_) {
        balance_ += diff;
    }
}

void Account::Lock() { is_locked_ = true; }
void Account::Unlock() { is_locked_ = false; }
