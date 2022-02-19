#include "Automaton_test.hpp"

#include <cassert>
#include <string>

Automaton_test::Automaton_test()
{
    automaton = new Automaton();
}

Automaton_test::~Automaton_test()
{
    delete automaton;
}

int Automaton_test::Test_Parsing()
{
    assert(
        automaton->Parsing("(34)")
            .expressionValue == 34
    );
    assert(
        automaton->Parsing("29930*34+10")
            .expressionValue == 1017630
    );
    assert(
        automaton->Parsing("46*(45+17*8)+(3*(12+1)+4)").expressionValue == 8369
    );
    return 0;
}