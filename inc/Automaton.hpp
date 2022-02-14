#pragma once
#include <vector>

#include "inc/state/State.hpp"
#include "inc/lexer/Symbol.hpp"

class Automaton
{
    public:
        std::vector<Symbol*> symbols;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        std::size_t cursorIndex; // used for tracking look ahead symbol (in yellow in the example picture)

        Automaton(string& inputExpression);
        virtual ~Automaton();
        bool Parsing();
};