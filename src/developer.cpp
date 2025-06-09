#include "developer.hpp"
#include <fstream>
#include <stdexcept>
#include <iterator>

Developer::Developer(const std::string& name, const std::string& alias)
    : name(name), alias(alias), logo("") {}

void Developer::drink_coffee() {
    std::cout << "Ahhhh, I needed that coffee!!!" << std::endl;
}

void Developer::load_logo_from_file(const std::string& filename) {
    std::ifstream file(DEV_LOGO_PATH + filename);
    if (!file) {
        throw std::runtime_error("Logo file could not be opened: " + filename);
    }
    logo.assign((std::istreambuf_iterator<char>(file)),
                 std::istreambuf_iterator<char>());
}

std::string Developer::get_name() const { return name; }
std::string Developer::get_alias() const { return alias; }
std::string Developer::get_logo() const { return logo; }

std::ostream& operator<<(std::ostream& os, const Developer& dev) {
    if (!dev.logo.empty()) {
        os << dev.logo << std::endl;
    }
    os << "Name: " << dev.name << std::endl;
    os << "Alias: " << dev.alias << std::endl;
    return os;
}
