#include <iostream>

#include "../inc/exception/NoActionException.hpp"
#include "../inc/exception/NoRuleException.hpp"
#include "../inc/lexer/Lexer.hpp"
#include "../inc/Automaton.hpp"
#include "../inc/state/State.hpp"

Automaton::Automaton()
{
    // Lexical Analysis
    // chain of symbols and stack

    // declare chain to be recognized
    string chaine("(1+34)*123");

    // create list of symbols with lexer
    Lexer l(chaine);
    Symbol * s;
    while((s = l.Consult())->ident != END) {
        s->Display();
        cout<<endl;
        chain.push_back(s);
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

bool Automaton::Parsing()
{
    // LR(1) parsing 
    // WARN: Don't get mixed up between stacks and arrays.
    stateStack.push_back(states[0]);
    symbolStack.push_back(chain[0]);
    bool isActionAccepted = false;
    do {
        try 
        {
            isActionAccepted = stateStack.back()->Action(chain.back());
        }
        catch (NoActionException& e)
        {
            cout<<"No action for this symbol"<<endl;
            return false;
        }
        catch (NoRuleException& e)
        {
            cout<<"No rule for this state"<<endl;
            return false;
        }
    } while (!isActionAccepted);

    // Action Accepted
    return true;
}