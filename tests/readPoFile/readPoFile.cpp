#include <gtest/gtest.h>

TEST(Test, readPoFile) {
    ASSERT_TRUE(42 > 24);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

