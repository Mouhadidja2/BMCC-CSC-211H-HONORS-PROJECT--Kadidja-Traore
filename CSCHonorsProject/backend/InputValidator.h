#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <stdexcept>

class InputValidator {
public:
    static void validateEmail(const std::string& email) {
        if (email.empty() || email.find("@") == std::string::npos) {
            throw std::invalid_argument("Invalid email. Email must contain @.");
        }
    }

    static void validateName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("Name cannot be empty.");
        }
    }
};
#endif // INPUTVALIDATOR_H
