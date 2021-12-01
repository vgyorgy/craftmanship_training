#include <iostream>
#include "dummy.h"

DummyClass::DummyClass()
{
    ;
}

DummyClass::~DummyClass()
{
    ;
}

void DummyClass::PrintSomething()
{
    std::cout << "print out stg ..." << std::endl;
};

int DummyClass::GetSomething()
{
    return 42;
}