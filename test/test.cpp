#include "../src/binding.h"
#include <gtest/gtest.h>

TEST(KeyBoardPress, Left_1)
{
    int a, b, c, d, e;
    a = 1;
    b = c = e = d = 1;
    int res = KeyBoardPressLeft(Keyboard::Left, a, b, c, d, e);
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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
