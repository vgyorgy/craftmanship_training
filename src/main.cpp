#include <iostream>

#include "dummy.h"

int main(int argc, char* argv[])
{
    std::cout << "hello" << std::endl;

    DummyClass dummy;

    dummy.PrintSomething();

    return 0;
}
