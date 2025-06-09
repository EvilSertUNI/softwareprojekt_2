#pragma once
#include <string>
#include <iostream>

class Developer {
protected:
    std::string name;
    std::string alias;
    std::string logo;

public:
    Developer(const std::string& name, const std::string& alias);
    virtual ~Developer() = default;

    static void drink_coffee();

    void load_logo_from_file(const std::string& filename);

    std::string get_name() const;
    std::string get_alias() const;
    std::string get_logo() const;

    virtual void solve_problem() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Developer& dev);
};