#include "developer.hpp"
#include <fstream>
#include <stdexcept>
#include <iterator>

// Initialize name and alias
Developer::Developer(const std::string& name, const std::string& alias)
    : name(name), alias(alias), logo("") {}

// Static method: Simulates a developer drinking coffee
void Developer::drink_coffee() {
    std::cout << "Ahhhh, I needed that coffee!!!" << std::endl;
}

// Loads logo content from file into logo string

void Developer::load_logo_from_file(const std::string& filename) {
    std::ifstream file(DEV_LOGO_PATH + filename);
    if (!file) {
        throw std::runtime_error("Logo file could not be opened: " + filename);
    }
    logo.assign((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());
    int remove_ws = 0;
    for (int ofs=logo.length() - 1; ofs > 0; --ofs) {
        if (logo[ofs] == '\n') {
            ++remove_ws;
            continue;
        }
        break;
    } 
    if (remove_ws) {
        logo.resize(logo.length() - remove_ws);
    } 
}

// Getter methods
std::string Developer::get_name() const { return name; }
std::string Developer::get_alias() const { return alias; }
std::string Developer::get_logo() const { return logo; }

// Stream output operator: Prints logo, name, and alias
std::ostream& operator<<(std::ostream& os, const Developer& dev) {
    if (!dev.logo.empty()) {

        os << dev.logo << std::endl;
    }
    os << "Name: " << dev.name << std::endl;
    os << "Alias: " << dev.alias << std::endl;
    return os;
}
