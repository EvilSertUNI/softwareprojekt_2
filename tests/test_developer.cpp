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

TEST_F(JuniorDeveloperTest, LoadLogo) {
    EXPECT_EQ(junior.get_logo(), "");
    junior.load_logo_from_file("test_junior_logo.txt");
    EXPECT_EQ(junior.get_logo(), "Junior Logo");
    EXPECT_THROW(junior.load_logo_from_file("nonexistent.txt"), std::runtime_error);
}

TEST_F(JuniorDeveloperTest, SolveProblem) {
    junior.load_logo_from_file("test_junior_logo.txt");
    testing::internal::CaptureStdout();
    junior.solve_problem();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = 
        "Solving a problem:\n"
        "Junior Logo\n"
        "Name: Test Junior\n"
        "Alias: TJ\n"
        "Ha, that was EZ!\n"
        "Ahhhh, I needed that coffee!!!\n";
    EXPECT_EQ(output, expected);
}

// Tests für SeniorDeveloper
TEST_F(SeniorDeveloperTest, ConstructorAndGetters) {
    EXPECT_EQ(senior.get_name(), "Test Senior");
    EXPECT_EQ(senior.get_alias(), "TS");
    EXPECT_EQ(senior.get_logo(), "");
}

TEST_F(SeniorDeveloperTest, LoadLogo) {
    EXPECT_EQ(senior.get_logo(), "");
    senior.load_logo_from_file("test_senior_logo.txt");
    EXPECT_EQ(senior.get_logo(), "Senior Logo");
    EXPECT_THROW(senior.load_logo_from_file("nonexistent.txt"), std::runtime_error);
}

TEST_F(SeniorDeveloperTest, SolveProblem) {
    senior.load_logo_from_file("test_senior_logo.txt");
    testing::internal::CaptureStdout();
    senior.solve_problem();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = 
        "Solving a problem:\n"
        "Senior Logo\n"
        "Name: Test Senior\n"
        "Alias: TS\n"
        "Puh, that was tough\n"
        "Ahhhh, I needed that coffee!!!\n";
    EXPECT_EQ(output, expected);
}
