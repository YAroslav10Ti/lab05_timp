#pragma once

class Account {
public:
    Account(int id, double balance);
    int GetId() const;
    double GetBalance() const;
    void ChangeBalance(double diff);
    void Lock();
    void Unlock();
    bool IsLocked() const;
private:
    int id_;
    double balance_;
    bool is_locked_;
};
