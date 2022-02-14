#pragma once
#include <vector>

#include "inc/state/State.hpp"
#include "inc/lexer/Symbol.hpp"

class Automaton
{
    public:
        std::vector<Symbol*> chain;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        Automaton();
        virtual ~Automaton();
        bool Parsing();
};