#include "../src/binding.h"
#include <gtest/gtest.h>

TEST(KeyBoardPress, Left_1)
{
    int a, b;
    a = 1;
    b = 1;
    int res = KeyBoardPressLeft(Keyboard::Left, a, b, b, b, b);
    ASSERT_EQ(res, 0);
}

TEST(KeyBoardPress, Left_2)
{
    int a, b, c, d, e;
    a = 1;
    b = c = e = d = 1;
    int res = KeyBoardPressLeft(Keyboard::Right, a, b, c, d, e);
    ASSERT_EQ(res, 1);
}

TEST(KeyBoardPress, Left_3)
{
    int a, b, c, d, e;
    a = 0;
    b = c = e = d = 1;
    int res = KeyBoardPressLeft(Keyboard::Left, a, b, c, d, e);
    ASSERT_EQ(res, 1);
}

TEST(KeyBoardPress, Up_1)
{
    int a, b;
    a = b = 1;
    int res = KeyBoardPressUp(Keyboard::Up, a, b, b, b, b);
    ASSERT_EQ(res, 0);
}

TEST(KeyBoardPress, Up_2)
{
    int a, b, c, d, e;
    a = 1;
    b = c = e = d = 1;
    int res = KeyBoardPressLeft(Keyboard::Down, e, b, c, d, a);
    ASSERT_EQ(res, 1);
}

TEST(KeyBoardPress, Up_3)
{
    int a, b, c, d, e;
    a = 0;
    b = c = e = d = 1;
    int res = KeyBoardPressLeft(Keyboard::Up, e, b, c, d, a);
    ASSERT_EQ(res, 1);
}

TEST(KeyBoardPress, Right_1)
{
    int a, b;
    a = 1;
    b = 0;
    int res = KeyBoardPressRight(Keyboard::Right, b, b, a, b, b);
    ASSERT_EQ(res, 0);
}

TEST(KeyBoardPress, Right_2)
{
    int a, b;
    a = b = 1;
    int res = KeyBoardPressRight(Keyboard::Down, b, b, a, b, b);
    ASSERT_EQ(res, 1);
}

TEST(KeyBoardPress, Right_3)
{
    int a, b;
    a = 0;
    b = 1;
    int res = KeyBoardPressRight(Keyboard::Right, b, b, a, b, b);
    ASSERT_EQ(res, 1);
}

TEST(KeyBoardPress, Down_1)
{
    int a, b;
    a = 1;
    b = 0;
    int res = KeyBoardPressDown(Keyboard::Down, b, b, b, a, b);
    ASSERT_EQ(res, 0);
}

TEST(KeyBoardPress, Down_2)
{
    int a, b;
    a = b = 1;
    int res = KeyBoardPressDown(Keyboard::Right, b, b, b, a, b);
    ASSERT_EQ(res, 1);
}

TEST(KeyBoardPress, Down_3)
{
    int a, b;
    a = 0;
    b = 1;
    int res = KeyBoardPressDown(Keyboard::Down, b, b, b, a, b);
    ASSERT_EQ(res, 1);
}

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
    int N = 100;
    srand(time(NULL));
    for (int i = 1; i < 100; i++)
        if (i % 5 == 0 && i != 1)
            ASSERT_EQ(SuperFructSpawn(i, a, a, a, N, N), 0);
        else
            ASSERT_EQ(SuperFructSpawn(i, a, a, a, N, N), 1);
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
