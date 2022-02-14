#include <iostream>
#include <exception>

class NoActionException : public std::runtime_error {

    public:
        NoActionException(
            const std::string& message
        ) : std::runtime_error(message) {}

        NoActionException() : std::runtime_error(
            "No action defined for the current state"
        ) {}
};