#include "junior_developer.hpp"

//pass parameters to the base class constuctor
JuniorDeveloper::JuniorDeveloper(const std::string& name, const std::string& alias)
    : Developer(name, alias) {}

// Implementation of problem solving for juniors
void JuniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:\n" << *this;
    std::cout << "Ha, that was EZ!" << std::endl;
    Developer::drink_coffee();
}