#include <iostream>
#include <stdexcept>
#include "init_project.h"

int InitProject::GetSomething()
{
    return 42;
}

String InitProject::GetHello()
{
    return "Hello!";
}

bool InitProject::GetFalse()
{
    return false;
}

void InitProject::GetThrowException()
{
    throw std::invalid_argument("hello");
}