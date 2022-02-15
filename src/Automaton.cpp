#include <iostream>
#include <string>

#include "exception/NoActionException.hpp"
#include "exception/NoRuleException.hpp"
#include "lexer/Lexer.hpp"
#include "Automaton.hpp"

Automaton::Automaton()
{
    cursorIndex = 0;
}

void Automaton::init(
    string& inputExpression, Automaton& automaton
)
{
    // init symbols first
    initSymbols(inputExpression);

    // init states
    initStates(automaton);
}

void Automaton::initSymbols(string& inputExpression)
{
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
}

void Automaton::initStates(Automaton& automaton)
{
    // LR(1) Ascending Syntax Analysis
    // states and state stack
    states.push_back(new I0(automaton));
    states.push_back(new I1(automaton));
    states.push_back(new I2(automaton));
    states.push_back(new I3(automaton));
    states.push_back(new I4(automaton));
    states.push_back(new I5(automaton));
    states.push_back(new I6(automaton));
    states.push_back(new I7(automaton));
    states.push_back(new I8(automaton));
    states.push_back(new I9(automaton));
}

bool Automaton::Parsing()
{
    // LR(1) parsing 
    // WARN: Don't get mixed up between stacks and arrays.
    stateStack.push_back(states[0]);
    symbolStack.push_back(symbols[0]);
    bool isActionAccepted = false;
    do {
        // action
        try 
        {
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