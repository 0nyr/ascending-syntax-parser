#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I7::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        r2(a);
    }
    else if(a->ident == MULT)
    {
        d(a, 5);
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I7::r2(Symbol* a)
{
    vector<Symbol*> poped;
  
    int value =0 ;

    for(int i=0;i<3;i++) {
        automaton.stateStack.pop_back();
        poped.push_back(automaton.symbolStack.back());
        automaton.symbolStack.pop_back();
    }

    // Here, a can be either PLUS, MULT, CLOSEPAR or END 
    // [E -> val. ,+,*,$,)] --- r2) E -> val
    switch (a->ident)
    {
    case PLUS:
        value = poped[0]->getValue() + poped[2]->getValue();
        break;
    default:
        break;
    }

    delete(automaton.symbolStack.back());
    automaton.symbolStack.push_back(new Int(value)); // convert to EXPR the last symbol of the stack
}