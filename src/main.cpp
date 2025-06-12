// -*- mode: cpp; truncate-lines: t -*-

#include <iostream>
#include <vector>
#include <memory>
#include "junior_developer.hpp"
#include "senior_developer.hpp"

int main(int argc, char **argv) {

    std::cout << "argc: " << argc << std::endl;
    if (argv[0] != NULL) {
        std::cout << "argv[0]: " << argv[0] << std::endl;
    }
    std::cout << std::endl;

    // Create vector of shared pointers to developers
    std::vector<std::shared_ptr<Developer>> developers;

    // Instantiate developers dynamically (via shared_ptr)
    auto junior = std::make_shared<JuniorDeveloper>("Ferdinand Leybach", "EvilSert");

    // Load their logos from text files (throws runtime_error if not found)

    // Since a missing logo does not prevent the developer from
    // solving the problem, only a warning is issued, so that the
    // more important task can be executed.
    try {
        junior->load_logo_from_file("junior_logo.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << "Warning loading logo: " << e.what() << std::endl;
    }
    try {
        junior->load_logo_from_file("junior_preferred_logo.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << "Warning loading logo: " << e.what() << std::endl;
    }
    // Add to vector
    developers.push_back(junior);

    auto senior = std::make_shared<SeniorDeveloper>("Simon Straub", "Der Allgäuer");
    try {
        senior->load_logo_from_file("senior_logo.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << "Warning loading logo: " << e.what() << std::endl;
    }
    try {
        senior->load_logo_from_file("senior_preferred_logo.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << "Warning loading logo: " << e.what() << std::endl;
    }
    developers.push_back(senior);

    // Iterate using iterator and invoke solve_problem() polymorphically
    for (auto it = developers.begin(); it != developers.end(); ++it) {
        (*it)->solve_problem();
    }

    return 0;
}
