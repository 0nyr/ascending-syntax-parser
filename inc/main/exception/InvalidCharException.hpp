#pragma once

#include <iostream>
#include <exception>

class InvalidCharException : public std::runtime_error {

    public:
        InvalidCharException(
            const std::string& message
        ) : std::runtime_error(message) {}

        InvalidCharException() : std::runtime_error(
            "Invalid char. At least on character of the input expression is invalid in the grammar."
        ) {}
};