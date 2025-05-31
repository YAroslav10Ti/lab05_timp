#include <gmock/gmock.h>
#include "Account.h"

class MockAccount : public Account {
public:
    MockAccount(int id, double balance) : Account(id, balance) {}
    MOCK_CONST_METHOD0(GetId, int());
    MOCK_CONST_METHOD0(GetBalance, double());
    MOCK_CONST_METHOD0(IsLocked, bool());
    MOCK_METHOD1(ChangeBalance, void(double));
    MOCK_METHOD0(Lock, void());
    MOCK_METHOD0(Unlock, void());
};
