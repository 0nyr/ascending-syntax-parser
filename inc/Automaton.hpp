#pragma once
#include <vector>

#include "lexer/Symbol.hpp"

class State;

class Automaton
{
    public:
        std::vector<Symbol*> symbols;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        std::size_t cursorIndex=0; // used for tracking look ahead symbol (in yellow in the example picture)

        Automaton(string& inputExpression);
        ~Automaton();
        bool Parsing();
};