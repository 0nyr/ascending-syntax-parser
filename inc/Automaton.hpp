#pragma once
#include <vector>

//#include "state/State.hpp" --> Use forward declaration
#include "lexer/Symbol.hpp"

// forward declaration, 
// then #include "state/State.hpp" in file
class State; // solves circular dependency

class Automaton
{
    public:
        std::vector<Symbol*> symbols;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        Automaton(string& inputExpression);
        ~Automaton();
        bool Parsing();

        inline void decrementCursorIndex()
        {
            this->cursorIndex--;
        }
    
    private:
        std::size_t cursorIndex; // used for tracking look ahead symbol (in yellow in the example picture)

        bool isActionAccepted();
        void printCurrentSituation();
};