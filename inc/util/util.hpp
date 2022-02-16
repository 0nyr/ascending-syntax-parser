#pragma once

#include <string>
#include <vector>

// colors
#define LIGHT_ORANGE "\e[38;5;216m"
#define TURQUOISE "\e[38;5;43m"
#define PALE_BLUE "\e[38;5;159m"
#define RED "\e[38;5;196m"
#define NO_COLOR "\e[0m"
#define GREY "\e[38;5;8m"
#define SILVER "\e[38;5;7m"
#define LIGHT_BLUE "\e[38;5;32m"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"

// debug mag
#ifdef DEBUG
#define debug(text) (std::cout << LIGHT_ORANGE << "[debug]: " << text << " (" << __FILE__ << ":" << __LINE__ << ")" << NO_COLOR << std::endl)
#define debugtv(text, value) (std::cout << LIGHT_ORANGE << "[debug]: " << text << " = " << value << " (" << __FILE__ << ":" << __LINE__ << ")" << NO_COLOR << std::endl)
#else
#define debug(expression) ((void)0)
#define debugtv(exp, var) ((void)0)
#endif


template <typename T>
std::string vectorToString(std::vector<T> const & vector) {
    std::string result = "[";
    for (int i = 0; i < vector.size(); i++) {
        if (i != 0) {
            result += ", ";
        }
        result += std::to_string(vector[i]);
    }
    result += "]";
    return result;
}

template<> inline
std::string vectorToString<Symbol*>(std::vector<Symbol*> const & vector) {
    std::string result = "[";
    for (int i = 0; i < vector.size(); i++) {
        if (i != 0) {
            result += ", ";
        }
        result += vector[i]->ToString();
    }
    result += "]";
    return result;
}

template<> inline
std::string vectorToString<State*>(std::vector<State*> const & vector) {
    std::string result = "[";
    for (int i = 0; i < vector.size(); i++) {
        if (i != 0) {
            result += ", ";
        }
        result += vector[i]->ToString();
    }
    result += "]";
    return result;
}


// function that prints a std::vector
template <typename T> 
void printVector(std::string const & vectorName, std::vector<T> const & vector) {
    // get type of T: https://stackoverflow.com/questions/1055452/c-get-name-of-type-in-template
    std::cout << vectorName << 
        "<" << typeid(T).name() << ">" 
        << ": [";
    for (int i = 0; i < vector.size(); i++)
    {
        if (i != 0)
        {
            std::cout << ", ";
        }
        std::cout << vector[i];
    }
    std::cout << "]" << std::endl;
}

// template specialization for printing std::vector<Symbol*>
template <> inline
void printVector<Symbol*>(
    std::string const & vectorName, 
    std::vector<Symbol*> const & vector
) {
    std::cout << vectorName << "<Symbol*>" << ": [";
    for (int i = 0; i < vector.size(); i++) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << vector[i]->ToString();
    }
    std::cout << "]" << std::endl;
}

// template specialization for printing std::vector>State*>
template <> inline
void printVector<State*>(
    std::string const & vectorName, 
    std::vector<State*> const & vector
) {
    std::cout << vectorName << "<State*>" << ": [";
    for (int i = 0; i < vector.size(); i++) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << vector[i]->ToString();
    }
    std::cout << "]" << std::endl;
}