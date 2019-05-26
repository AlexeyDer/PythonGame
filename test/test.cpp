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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
