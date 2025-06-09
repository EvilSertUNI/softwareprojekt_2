#include <vector>
#include <memory>
#include <iostream>

#include "junior_developer.hpp"
#include "senior_developer.hpp"

int main() {
    std::vector<std::shared_ptr<Developer>> developers;

    auto junior = std::make_shared<JuniorDeveloper>("Ferdinand Laybach", "EvilSert");
    auto senior = std::make_shared<SeniorDeveloper>("Simon Straub", "der Allgäuer");

    try {
        junior->load_logo_from_file("junior_logo.txt");
        senior->load_logo_from_file("senior_logo.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << "Error loading logo: " << e.what() << std::endl;
    }

    developers.push_back(junior);
    developers.push_back(senior);

    for (auto it = developers.begin(); it != developers.end(); ++it) {
        (*it)->solve_problem();
    }

    return 0;
}
