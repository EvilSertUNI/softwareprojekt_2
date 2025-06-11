#pragma once
#include "developer.hpp"

//derived class of the base class Developer to represent the senior developer
class SeniorDeveloper : public Developer {
public:
    //The Constructor calls the base class constructor
    SeniorDeveloper(const std::string& name, const std::string& alias);
    //Implements solving a problem in senior style
    void solve_problem() const override;
};