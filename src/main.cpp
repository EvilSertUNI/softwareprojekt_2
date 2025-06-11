#include <iostream>
#include <vector>
#include <memory>
#include "junior_developer.hpp"
#include "senior_developer.hpp"

int main() {
    // Create vector of shared pointers to developers
    std::vector<std::shared_ptr<Developer>> developers;

    // Instantiate developers dynamically (via shared_ptr)
    auto junior = std::make_shared<JuniorDeveloper>("Ferdinand Leybach", "EvilSert");
    auto senior = std::make_shared<SeniorDeveloper>("Simon Straub", "The Allgäuer");

    // Load their logos from text files (throws runtime_error if not found)
    try {
        junior->load_logo_from_file("junior_logo.txt");
        senior->load_logo_from_file("senior_logo.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << "Error loading logo: " << e.what() << std::endl;
    }

    // Add to vector
    developers.push_back(junior);
    developers.push_back(senior);

    // Iterate using iterator and invoke solve_problem() polymorphically
    for (auto it = developers.begin(); it != developers.end(); ++it) {
        (*it)->solve_problem();
    }

    return 0;
}