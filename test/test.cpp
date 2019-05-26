#include "../src/binding.h"
#include <gtest/gtest.h>

TEST(MovingPuzzle, move_1)
{
    ASSERT_EQ(2, 2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
