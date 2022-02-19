#include "exception/NoActionException.hpp"
#include "lexer/Lexer.hpp"
#include "Automaton.hpp"
#include "state/State.hpp" // resolve circular dependency
#include "util/util.hpp"

#include <iostream>
#include <string>

Automaton::Automaton()
{}

Automaton::~Automaton()
{
    clean();
}

void Automaton::clean()
{
    deleteVectors();
    clearVectors();
}

void Automaton::deleteVectors()
{
    // free relevant vectors memory
    for (State* state : states)
    {
        delete state;
    }
    for (Symbol* symbol : symbols)
    {
        delete symbol;
    }
}

void Automaton::clearVectors()
{
    states.clear();
    symbols.clear();
    stateStack.clear();
    symbolStack.clear();
}

void Automaton::init(string const & inputExpression)
{
    // erase old stuff
    clean();

    // init new stuff
    cursorIndex = 0;

    lexicalAnalysis(inputExpression);
}

void Automaton::lexicalAnalysis(std::string const & inputExpression)
{
    // create list of symbols with lexer
    Lexer l(inputExpression);
    Symbol * s;
    do {
        s = l.Consult();
        symbols.push_back(s);
        l.Advance();
    } while (s->ident != END);

    printVector("symbols", symbols);

    // states and state stack
    states.push_back(new I0(*this));
    states.push_back(new I1(*this));
    states.push_back(new I2(*this));
    states.push_back(new I3(*this));
    states.push_back(new I4(*this));
    states.push_back(new I5(*this));
    states.push_back(new I6(*this));
    states.push_back(new I7(*this));
    states.push_back(new I8(*this));
    states.push_back(new I9(*this));
    
    printVector("states", states);
}

ParsingResult Automaton::Parsing(std::string const & inputExpression)
{
    init(inputExpression);

    // LR(1) parsing 
    // WARN: Don't get mixed up between stacks and arrays.
    stateStack.push_back(states[cursorIndex]);
    // symbolStack starts empty
    printCurrentSituation();
    
    ParsingResult parsingResult;

    do {
        try 
        {
            parsingResult = this->isActionAccepted();
        }
        catch (NoActionException& error)
        {
            std::cout<<"No action for this symbol"<<std::endl;
            return parsingResult;
        }
        cursorIndex++; // must be placed before printing
        if(!parsingResult.isParsingSuccessful)
        {
            printCurrentSituation();
        }
    } while (!parsingResult.isParsingSuccessful);

    // Action Accepted
    return parsingResult;
}

ParsingResult Automaton::isActionAccepted()
{
    Symbol* a = symbols[cursorIndex];
    return stateStack.back()->Action(a);
}

void Automaton::printCurrentSituation()
{
    std::string logLine = "";

    // get stateStack
    #ifdef COLORS
    logLine += TURQUOISE;
    #endif
    logLine += vectorToString(stateStack);
    int nbMissingSpaces = 50 - logLine.size();

    #ifdef COLORS
    logLine += PALE_BLUE;
    #endif
    // get symbolStack
    for (int i = 0; i < nbMissingSpaces; i++)
        logLine += " ";
    logLine += vectorToString(symbolStack);

    #ifdef COLORS
    logLine += LIGHT_YELLOW;
    #endif
    // print lookup, check if cursorIndex is within bounds of symbols vector
    logLine += "[";
    if (
        cursorIndex < symbols.size() &&
        cursorIndex >= 0
    ) {
        logLine += symbols[cursorIndex]->ToString();
    }
    logLine += "]";

    #ifdef COLORS
    logLine += NO_COLOR; 
    #endif
    std::cout << logLine << std::endl;
}

