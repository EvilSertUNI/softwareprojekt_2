#include "senior_developer.hpp"

SeniorDeveloper::SeniorDeveloper(const std::string& name, const std::string& alias)
    : Developer(name, alias) {}

void SeniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:\n" << *this;
    std::cout << "Puh, that was tough" << std::endl;
    Developer::drink_coffee();
}