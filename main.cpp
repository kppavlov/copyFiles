#include <iostream>
#include <string>
#include "fsOperations.hpp"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

int main(int argc, char **arg)
{
    // cast char to string
    std::string arg1(arg[1]);
    std::string arg2(arg[2]);
    std::string arg3(arg[3]);
    std::string arg4(arg[4]);
    std::string arg5(arg[5]);

    FsOperations construct(arg2, arg3, arg5);
    FsOperations construct1 = construct;

    if (arg2 == "-h" || arg2 == "--help" || arg2 != "-i")
    {
        construct.drawHelp();
        return 1;
    }

    construct.whatToDo(arg1);

    return 0;
}