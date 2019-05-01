#include <iostream>
#include <string>
#include "Operations.h"

using namespace std;

Operations::Operations() {}
Operations::~Operations()
{
    cout << "Operations free up memory \n";
}

void Operations::doOperation()
{
    std::cout << "Do some crazy stuff here Operations::doOperation()"
              << "\n";
}

void Operations::setPathFrom(char *from)
{
    pathFrom = from;
}

void Operations::setPathTo(char *to)
{
    pathTo = to;
}
