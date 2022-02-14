#pragma once
#include <vector>

#include "lexer/Symbol.hpp"

class State;

class Automaton
{
    public:
        Automaton();
        ~Automaton();
        bool Parsing();

        std::vector<Symbol*> chain;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        
};