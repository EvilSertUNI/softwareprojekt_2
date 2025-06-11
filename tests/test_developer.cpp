#include <gtest/gtest.h>
#include "junior_developer.hpp"
#include "senior_developer.hpp"
#include <stdexcept>

// Test Fixture für JuniorDeveloper
class JuniorDeveloperTest : public ::testing::Test {
protected:
    JuniorDeveloper junior{"Test Junior", "TJ"};
};

// Test Fixture für SeniorDeveloper
class SeniorDeveloperTest : public ::testing::Test {
protected:
    SeniorDeveloper senior{"Test Senior", "TS"};
};

// Tests für JuniorDeveloper
TEST_F(JuniorDeveloperTest, ConstructorAndGetters) {
    EXPECT_EQ(junior.get_name(), "Test Junior");
    EXPECT_EQ(junior.get_alias(), "TJ");
    EXPECT_EQ(junior.get_logo(), "");
}
