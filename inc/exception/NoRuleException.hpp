#include <iostream>
#include <exception>

class NoRuleException : public std::runtime_error {

    public:
        NoRuleException(
            const std::string& message
        ) : std::runtime_error(message) {}

        NoRuleException() : std::runtime_error(
            "No rule of the form [E -> [...] ,x,y,z,] defined for the current state"
        ) {}
};