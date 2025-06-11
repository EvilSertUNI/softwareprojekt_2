#pragma once
#include "developer.hpp"

//derived class of the base class Developer to represent the junior developer
class JuniorDeveloper : public Developer {
public:
    //The Constructor calls the base class constructor
    JuniorDeveloper(const std::string& name, const std::string& alias);
    
    //Implements solving a problem in junior style
    void solve_problem() const override;
};