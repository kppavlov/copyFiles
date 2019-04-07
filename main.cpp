#include <iostream>
#include <string>
#include "copyFiles.hpp"
using namespace std;

int main(int argc, char **arg)
{
    Copy init;
    init.readArgs(argc, arg);
    try
    {
        init.copy();
    }
    catch (const std::exception &e)
    {
        init.catchError(e);
        return 1;
    }

    return 0;
}