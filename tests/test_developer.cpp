#include <gtest/gtest.h>
#include "junior_developer.hpp"
#include "senior_developer.hpp"
#include <stdexcept>

// Test fixture for Developer classes
class DeveloperTest : public ::testing::Test {
protected:
    // Common test data
    std::string test_name = "Test Name";
    std::string test_alias = "Test Alias";
    std::string valid_logo_file = "junior_logo.txt";
    std::string invalid_logo_file = "invalid_logo.txt";
};

// Test for JuniorDeveloper constructor and getters
TEST_F(DeveloperTest, JuniorDeveloperConstructorAndGetters) {
    JuniorDeveloper junior(test_name, test_alias);
    EXPECT_EQ(junior.get_name(), test_name);
    EXPECT_EQ(junior.get_alias(), test_alias);
    EXPECT_EQ(junior.get_logo(), "");
}

// Test for SeniorDeveloper constructor and getters
TEST_F(DeveloperTest, SeniorDeveloperConstructorAndGetters) {
    SeniorDeveloper senior(test_name, test_alias);
    EXPECT_EQ(senior.get_name(), test_name);
    EXPECT_EQ(senior.get_alias(), test_alias);
    EXPECT_EQ(senior.get_logo(), "");
}

// Test for load_logo_from_file with valid file
TEST_F(DeveloperTest, LoadLogoFromValidFile) {
    JuniorDeveloper junior(test_name, test_alias);
    junior.load_logo_from_file(valid_logo_file);
    std::string logo = junior.get_logo();
    EXPECT_FALSE(logo.empty());
}

// Test for load_logo_from_file with invalid file
TEST_F(DeveloperTest, LoadLogoFromInvalidFile) {
    JuniorDeveloper junior(test_name, test_alias);
    EXPECT_THROW(junior.load_logo_from_file(invalid_logo_file), std::runtime_error);
}

// Test that the logo is empty before loading
TEST_F(DeveloperTest, LogoEmptyBeforeLoading) {
    JuniorDeveloper junior(test_name, test_alias);
    EXPECT_EQ(junior.get_logo(), "");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
