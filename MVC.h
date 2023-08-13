#pragma once

#include "Observer.h"
#include "CLI.h"

class View : public Observer
{
    CLI* cli;
public:
    View(Subject* model, CLI c)
    {
        model->attach(this);
        cli = &c;
    }
    /* virtual */void update(int v)
    {
        
    }
};

class Controller : public Observer
{

};

class Model : public Subject {

};