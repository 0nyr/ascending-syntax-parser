#pragma once
#include <vector>

#include "state/State.hpp" // circular dependency
#include "lexer/Symbol.hpp"

class State; // solves circular dependency

class Automaton
{
    public:
        std::vector<Symbol*> symbols;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        std::size_t cursorIndex; // used for tracking look ahead symbol (in yellow in the example picture)

        Automaton();
        virtual ~Automaton();
        bool Parsing();
        void init(
            string& inputExpression, 
            Automaton& automaton
        );

    private:
        void initSymbols(string& inputExpression);
        void initStates(Automaton& automaton);
};