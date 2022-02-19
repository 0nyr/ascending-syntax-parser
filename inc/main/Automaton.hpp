#pragma once

//#include "state/State.hpp" --> Use forward declaration
#include "lexer/Symbol.hpp"

// forward declaration, 
// then #include "state/State.hpp" in file
class State; // solves circular dependency

#include <vector>

class Automaton
{
    public:
        std::vector<Symbol*> symbols;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        Automaton();
        ~Automaton();
        bool Parsing(std::string& inputExpression);

        inline void lookBackCursorIndex(int nbRemovedSymbols)
        {
            // - 1 because after, in Parsing(), cursorIndex is incremented by 1
            // and we want it to be -nbRemovedSymbols at the end of the current parsing loop
            this->cursorIndex = this->cursorIndex - nbRemovedSymbols - 1 ;
        }
    
    private:
        std::size_t cursorIndex; // used for tracking look ahead symbol (in yellow in the example picture)

        void init(std::string& inputExpression);
        void lexicalAnalysis(std::string& inputExpression);
        void clean();
        void deleteVectors();
        void clearVectors();
        bool isActionAccepted();
        void printCurrentSituation();
};