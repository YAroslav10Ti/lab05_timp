#include <gtest/gtest.h>
#include "MockBanking.cpp"

TEST(AccountTest, BasicFunctionality) {
    Account acc(1, 100.0);
    EXPECT_EQ(acc.GetId(), 1);
    EXPECT_EQ(acc.GetBalance(), 100.0);
    EXPECT_FALSE(acc.IsLocked());
    
    acc.ChangeBalance(50.0);
    EXPECT_EQ(acc.GetBalance(), 150.0);
    
    acc.Lock();
    EXPECT_TRUE(acc.IsLocked());
    acc.ChangeBalance(50.0);  // Не должно измениться
    EXPECT_EQ(acc.GetBalance(), 150.0);
    
    acc.Unlock();
    EXPECT_FALSE(acc.IsLocked());
}
