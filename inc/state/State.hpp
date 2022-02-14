#pragma once
#include <vector>

#include "inc/Automaton.hpp"
#include "inc/lexer/Symbol.hpp"

class State
{
    public:
        State(
            Automaton& automaton
        ) : automaton(automaton) {};
        virtual ~State(); 
        virtual bool Action(Symbol* a);
    
    protected:
        Automaton& automaton;
};

class I0 : public State
{
    public:
        I0();
        virtual ~I0();
        bool Action(Symbol* a);

        void d2();
        void d3();
        void transition(State* nextState);
};

class I1 : public State
{
    public:
        I1();
        virtual ~I1();
        bool Action(Symbol* a);
        
        void d4();
        void d5();
};

class I2 : public State
{
    public:
        I2();
        virtual ~I2();
        bool Action(Symbol* a);
        
        void d2();
        void d3();
        void transition(State* nextState);
};

class I3 : public State
{
    public:
        I3();
        virtual ~I3();
        bool Action(Symbol* a);
        
        void r5();
};

class I4 : public State
{
    public:
        I4();
        virtual ~I4();
        bool Action(Symbol* a);
        
        void d2();
        void d3();
        void transition(State* nextState);
};

class I5 : public State
{
    public:
        I5();
        virtual ~I5();
        bool Action(Symbol* a);
        
        void d2();
        void d3();
        void transition(State* nextState);
};

class I6 : public State
{
    public:
        I6();
        virtual ~I6();
        bool Action(Symbol* a);
        
        void d4();
        void d5();
        void d9();
};

class I7 : public State
{
    public:
        I7();
        virtual ~I7();
        bool Action(Symbol* a);
        
        void r2();
        void d5();
};

class I8 : public State
{
    public:
        I8();
        virtual ~I8();
        bool Action(Symbol* a);
        
        void r3();
};

class I9 : public State
{
    public:
        I9();
        virtual ~I9();
        bool Action(Symbol* a);
        
        void r4();
};