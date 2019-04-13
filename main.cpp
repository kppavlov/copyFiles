#include <iostream>
#include <string>
#include "fsOperations.hpp"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

void printUsage()
{
    std::cout << "Usage\n";
    std::cout << "-operation[-c, -rn, -rm] -input_path[-i /path/do/modify..] -output_path[-o /path/to/paste] \n";
    std::cout << "-c Copy files/directories\n";
    std::cout << "-rn Rename files/directories\n";
    std::cout << "-rm Remove files/directories\n";
    std::cout << "-i path to file or directory to copy\n";
    std::cout << "-o path to directory to paste\n";
    std::cout << "-h || --help to print this help\n";
    exit(EXIT_FAILURE);
}

int main(int argc, char **arg)
{
    if (argc == 1 || argc <= 3 || argc == 5 || argc > 6)
    {
        cout << "pyrvi if\n";
        printUsage();
    }

    string arg1(arg[1]);
    string arg2(arg[2]);
    if (arg1 == "-h" || arg1 == "--help" ||
        arg2 != "-i")
    {
        cout << "vtori if\n";
        printUsage();
    }

    if (argc == 4)
    {
        if (arg1 != "-rm")
        {
            printUsage();
        }

        Remove remove(arg[3]);
        remove.remove();
    }

    if (argc == 6)
    {
        if (arg1 == "-rn")
        {
            Rename rename(arg[3], arg[5]);
            rename.rename();
        }
        else
        {
            Copy cpy(arg[3], arg[5]);
            cpy.copy();
        }
    }

    return 0;
}