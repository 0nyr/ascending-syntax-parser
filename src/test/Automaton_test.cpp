#include "Automaton_test.hpp"

Automaton_test::Automaton_test()
{
    automaton = new Automaton();
}

Automaton_test::~Automaton_test()
{
    delete automaton;
}