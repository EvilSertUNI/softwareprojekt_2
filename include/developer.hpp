#pragma once
#include <string>
#include <iostream>

//Abstract base class for all Developer types
class Developer {
protected:
    std::string name;   //The Name of the Developer
    std::string alias;  //the nick-name 
    std::string logo;   //thte string of the Logo

public:
    //The Constructor initializing name and the nick name
    Developer(const std::string& name, const std::string& alias);
    //Deconstructor
    virtual ~Developer() = default;

    //Static itility method 
    static void drink_coffee();
    //now the logo 
    void load_logo_from_file(const std::string& filename);

    //Accessors
    std::string get_name() const;
    std::string get_alias() const;
    std::string get_logo() const;

    //Abstract method that will be implemented by derived classes
    virtual void solve_problem() const = 0;

    //Stream operator which makes printing easy
    friend std::ostream& operator<<(std::ostream& os, const Developer& dev);
};