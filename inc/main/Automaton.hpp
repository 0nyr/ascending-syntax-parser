#pragma once

//#include "state/State.hpp" --> Use forward declaration
#include "lexer/Symbol.hpp"

// forward declaration, 
// then #include "state/State.hpp" in file
class State; // solves circular dependency

#include <vector>

struct ParsingResult
{
    bool isParsingSuccessful = false;
    int expressionValue = 0;
};

class Automaton
{
    public:
        std::vector<Symbol*> symbols;
        std::vector<Symbol*> symbolStack;

        std::vector<State*> states;
        std::vector<State*> stateStack;

        Automaton();
        ~Automaton();
        ParsingResult Parsing(std::string const & inputExpression);

        inline void lookBackCursorIndex(int nbRemovedSymbols)
        {
            // - 1 because after, in Parsing(), cursorIndex is incremented by 1
            // and we want it to be -nbRemovedSymbols at the end of the current parsing loop
            this->cursorIndex = this->cursorIndex - nbRemovedSymbols - 1 ;
        }
    
    private:
        std::size_t cursorIndex; // used for tracking look ahead symbol (in yellow in the example picture)

        void init(std::string const & inputExpression);
        void lexicalAnalysis(std::string const & inputExpression);
        void clean();
        void deleteVectors();
        void clearVectors();
        ParsingResult isActionAccepted();
        void printCurrentSituation();
};