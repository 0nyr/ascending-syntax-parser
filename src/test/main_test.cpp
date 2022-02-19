#include "Automaton_test.hpp"

// define functions
void test_Automaton();

int main()
{
    test_Automaton();
    return 0;
}

void test_Automaton()
{
    Automaton_test automaton_test = Automaton_test();
    automaton_test.Test_Parsing();
}