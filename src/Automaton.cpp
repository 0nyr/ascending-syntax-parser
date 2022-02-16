#include <iostream>
#include <string>

#include "exception/NoActionException.hpp"
#include "lexer/Lexer.hpp"
#include "Automaton.hpp"
#include "state/State.hpp" // resolve circular dependency
#include "util/util.hpp"

Automaton::Automaton(string& inputExpression)
{
    // init attributes 
    cursorIndex = 0;

    // Lexical Analysis
    // chain of symbols and stack

    // create list of symbols with lexer
    Lexer l(inputExpression);
    Symbol * s;
    do {
        s = l.Consult();
        symbols.push_back(s);
        l.Advance();
    } while (s->ident != END);

    printVector("symbols", symbols);

    // LR(1) Ascending Syntax Analysis
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

Automaton::~Automaton(){
    states.clear();
    symbols.clear();
}

bool Automaton::Parsing()
{
    // LR(1) parsing 
    // WARN: Don't get mixed up between stacks and arrays.
    stateStack.push_back(states[0]);
    // symbolStack starts empty
    printCurrentSituation();
    
    bool isActionAccepted = false;

    do {
        try 
        {
            isActionAccepted = this->isActionAccepted();
        }
        catch (NoActionException& e)
        {
            std::cout<<"No action for this symbol"<<std::endl;
            return false;
        }

        printCurrentSituation();

        // cursor increment
        cursorIndex++;
    } while (!isActionAccepted);

    // Action Accepted
    return true;
}

bool Automaton::isActionAccepted()
{
    Symbol* a = symbols[cursorIndex];
    bool isActionAccepted = stateStack.back()->Action(
        a
    );
    return isActionAccepted;
}

void Automaton::printCurrentSituation()
{
    std::string logLine;
    logLine = vectorToString(stateStack);
    int nbMissingSpaces = 30 - logLine.size();
    for (int i = 0; i < nbMissingSpaces; i++)
        logLine += " ";
    logLine += vectorToString(symbolStack);
    logLine += "[" + symbols[cursorIndex]->ToString() + "]";
    std::cout << logLine << std::endl;
}

