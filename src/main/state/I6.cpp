#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

ParsingResult I6::Action(Symbol* a)
{
    if (a->ident == PLUS)
    {
        d(a, 4);
    }
    else if(a->ident == MULT)
    {
        d(a, 5);
    }
    else if(a->ident == CLOSEPAR)
    {
        d(a ,9);
    }
    else 
    {
        throw NoActionException();
    }
    return ParsingResult(); // not accepting
}