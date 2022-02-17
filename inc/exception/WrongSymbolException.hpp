#pragma once

#include <iostream>
#include <exception>

class WrongSymbolException : public std::runtime_error {

    public:
        WrongSymbolException(
            const std::string& message
        ) : std::runtime_error(message) {}

        WrongSymbolException() : std::runtime_error(
            "Wrong symbol, expected something else"
        ) {}
};