#include "../src/binding.h"
#include <gtest/gtest.h>

TEST(TurnSnake, Down)
{
    int res = TurnSnake(0);
    ASSERT_EQ(res, 0);
}

TEST(TurnSnake, Up)
{
    int res = TurnSnake(3);
    ASSERT_EQ(res, 3);
}

TEST(TurnSnake, Left)
{
    int res = TurnSnake(1);
    ASSERT_EQ(res, 1);
}

TEST(TurnSnake, Right)
{
    int res = TurnSnake(2);
    ASSERT_EQ(res, 2);
}

TEST(TeleportationSnake, AroundTheBoard)
{
    int n = 10;
    int a = -1;
    int b = 12;

    int R = TeleportationSnake(a, n);
    int L = TeleportationSnake(b, n);
    for (int i = 0; i < n; i++) {
        ASSERT_EQ(TeleportationSnake(i, n), 1);
    }
    ASSERT_EQ(R, 0);
    ASSERT_EQ(L, 0);
}

TEST(SuperFructSpawn, Spawn)
{
    int a = 1;
    int b = 2;
    int c = 3;
    int N = 10;
    int M = 110;
    srand(time(NULL));
    for (int i = 1; i < 100; i++)
        if (i % 5 == 0)
            ASSERT_EQ(SuperFructSpawn(i, a, b, c, N, M), 0);
        else
            ASSERT_EQ(SuperFructSpawn(i, a, b, c, N, M), 1);
}

TEST(UpSpeed, Levels)
{
    int a = 1;
    int b = 2;
    int c = 3;
    float f = 0.1;

    for (int i = 0; i < 100; i++) {
        if (i < 6)
            ASSERT_EQ(UpSpeed(i, f, a), 0);
        else if (i < 11)
            ASSERT_EQ(UpSpeed(i, f, b), 1);
        else if (i < 16)
            ASSERT_EQ(UpSpeed(i, f, c), 2);
        else
            ASSERT_EQ(UpSpeed(i, f, a), 3);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
