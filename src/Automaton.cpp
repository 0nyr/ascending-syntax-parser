#include <iostream>
#include <string>

#include "exception/NoActionException.hpp"
#include "exception/NoRuleException.hpp"
#include "lexer/Lexer.hpp"
#include "Automaton.hpp"
#include "state/State.hpp" // resolve circular dependency

Automaton::Automaton(string& inputExpression)
{
    // init attributes 
    cursorIndex = 0;

    // Lexical Analysis
    // chain of symbols and stack

    // create list of symbols with lexer
    Lexer l(inputExpression);
    Symbol * s;
    while((s = l.Consult())->ident != END) {
        s->Display();
        std::cout<<std::endl;
        symbols.push_back(s);
        l.Advance();
    }



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
    symbolStack.push_back(symbols[0]);
    bool isActionAccepted = false;

    for(int i = 0; i<symbols.size();i++)
        std::cout<<symbols[i]->ident<<std::endl;
    do {
        // action
        try 
        {
            std::cout << stateStack.back()->toString() << 
                "/ cursordIndex : " << cursorIndex << 
                " / symbolStack " << symbolStack[cursorIndex]->ident <<
                " / size symbol stack : " << symbolStack.size() << 
                std::endl;
            isActionAccepted = stateStack.back()->Action(
                symbolStack[cursorIndex]
            );
        }
        catch (NoActionException& e)
        {
            std::cout<<"No action for this symbol"<<std::endl;
            return false;
        }
        catch (NoRuleException& e)
        {
            std::cout<<"No rule for this state"<<std::endl;
            return false;
        }

        // cursor increment
        cursorIndex++;
    } while (!isActionAccepted);

    // Action Accepted
    return true;
}