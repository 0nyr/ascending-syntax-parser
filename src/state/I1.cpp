#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I1::Action(Symbol* a)
{
    
    if (a->ident == INT)
    {
        d(a, 4);
    }
    else if(a->ident == OPENPAR)
    {
        d(a, 5);
    }
    else if(a->ident == END)
    {
        return accept(); // accepting
    } 
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

bool I1::accept()
{
    std::cout << "<<< END reached, expression accepted >>>" << std::endl;
    return true;
}