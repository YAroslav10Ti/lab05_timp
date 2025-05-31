#include <gtest/gtest.h>
#include "MockBanking.cpp"

TEST(TransactionTest, SuccessfulTransaction) {
    MockAccount from(1, 200.0);
    MockAccount to(2, 50.0);
    Transaction t;
    t.set_fee(10.0);
    
    EXPECT_CALL(from, GetId()).WillOnce(testing::Return(1));
    EXPECT_CALL(to, GetId()).WillOnce(testing::Return(2));
    EXPECT_CALL(from, IsLocked()).WillOnce(testing::Return(false));
    EXPECT_CALL(to, IsLocked()).WillOnce(testing::Return(false));
    EXPECT_CALL(from, GetBalance()).WillOnce(testing::Return(200.0));
    EXPECT_CALL(from, ChangeBalance(testing::_)).Times(1);
    EXPECT_CALL(to, ChangeBalance(testing::_)).Times(1);
    
    EXPECT_TRUE(t.Make(from, to, 100.0));
}

TEST(TransactionTest, FailedTransactions) {
    // Тест на перевод самому себе
    {
        MockAccount acc(1, 100.0);
        Transaction t;
        EXPECT_CALL(acc, GetId()).WillOnce(testing::Return(1));
        EXPECT_FALSE(t.Make(acc, acc, 50.0));
    }
    
    // Тест на отрицательную сумму
    {
        MockAccount from(1, 100.0);
        MockAccount to(2, 50.0);
        Transaction t;
        EXPECT_FALSE(t.Make(from, to, -50.0));
    }
    
    // Тест на заблокированный аккаунт
    {
        MockAccount from(1, 100.0);
        MockAccount to(2, 50.0);
        Transaction t;
        EXPECT_CALL(from, GetId()).WillOnce(testing::Return(1));
        EXPECT_CALL(to, GetId()).WillOnce(testing::Return(2));
        EXPECT_CALL(from, IsLocked()).WillOnce(testing::Return(true));
        EXPECT_FALSE(t.Make(from, to, 50.0));
    }
    
    // Тест на недостаточно средств
    {
        MockAccount from(1, 50.0);
        MockAccount to(2, 100.0);
        Transaction t;
        t.set_fee(10.0);
        EXPECT_CALL(from, GetId()).WillOnce(testing::Return(1));
        EXPECT_CALL(to, GetId()).WillOnce(testing::Return(2));
        EXPECT_CALL(from, IsLocked()).WillOnce(testing::Return(false));
        EXPECT_CALL(to, IsLocked()).WillOnce(testing::Return(false));
        EXPECT_CALL(from, GetBalance()).WillOnce(testing::Return(50.0));
        EXPECT_FALSE(t.Make(from, to, 50.0));
    }
}
