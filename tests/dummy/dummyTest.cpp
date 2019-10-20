#include <gtest/gtest.h>
#include "Sentence.hpp"

TEST(Test, cppVersion) {
    ASSERT_TRUE(42 > 24);
}

TEST(Test, dummy01) {
    ASSERT_TRUE(1.0f == makeMeasure("foo", "foo"));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

