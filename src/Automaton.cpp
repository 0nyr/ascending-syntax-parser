#include "inc/lexer/Lexer.hpp"
#include "inc/Automaton.hpp"

Automaton::Automaton()
{
    // Lexical Analysis
    // chain of symbols and stack

    // declare chain to be recognized
    string chaine("(1+34)*123");

    // create list of symbols with lexer
    Lexer l(chaine);
    Symbol * s;
    while(*(s=l.Consult())!=FIN) {
        s->Display();
        cout<<endl;
        chain.push_back(s);
        l.Advance();
    }



    // LR(1) Ascending Syntax Analysis
    // states and state stack

    states.push_back(new I0(this));
    states.push_back(new I1(this));
    states.push_back(new I2(this));
    states.push_back(new I3(this));
    states.push_back(new I4(this));
    states.push_back(new I5(this));
    states.push_back(new I6(this));
    states.push_back(new I7(this));
    states.push_back(new I8(this));
    states.push_back(new I9(this));
}

Automaton::Parsing()
{
    // LR(1) parsing
    states.push_back(i0);
    symbols.push_back(chain[0]);
    while (!states.back()->Action(chain.back())) {}
}