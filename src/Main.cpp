#include <vector>
#include <iostream>


#include "inc/state/State.hpp"
#include "inc/lexer/Symbol.hpp"
#include "inc/Automaton.hpp"

void main()
{

    // declare expression to be recognized
    string inputExpression("(1+34)*123");

    // check if the expression is valid
    Automaton automaton = Automaton(
        inputExpression
    );
    bool isExpressionValid = automaton.Parsing();
    if (isExpressionValid)
    {
        std::cout<<"Expression is valid"<<std::endl;
    }
    else
    {
        std::cout<<"Expression is invalid"<<std::endl;
    }

}


