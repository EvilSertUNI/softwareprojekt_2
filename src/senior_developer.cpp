#include "senior_developer.hpp"

//pass parameters to the base class constuctor
SeniorDeveloper::SeniorDeveloper(const std::string& name, const std::string& alias)
    : Developer(name, alias) {}

// Implementation of problem solving for serniors
void SeniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:\n" << *this;
    std::cout << "Puh, that was tough" << std::endl;
    Developer::drink_coffee();
}