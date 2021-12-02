#include <iostream>
#include <stdexcept>
#include "init_project.h"

int InitProject::GetSomething()
{
    return 42;
}

bool InitProject::GetFalse()
{
    return false;
}

void InitProject::GetThrowException()
{
    throw std::invalid_argument("hello");
}