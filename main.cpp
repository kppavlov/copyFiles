#include <iostream>
#include <string>
#include "Copy.h"
#include "Rename.h"
#include "Remove.h"
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
        printUsage();
    }

    string arg1(arg[1]);
    string arg2(arg[2]);
    if (arg1 == "-h" || arg1 == "--help" ||
        arg2 != "-i")
    {
        printUsage();
    }

    Operations *op;

    if (argc == 4)
    {
        if (arg1 != "-rm")
        {
            printUsage();
        }

        string const arg31(arg[3]);
        Remove remove(arg31);
        op = &remove;
        op->doOperation();
    }

    if (argc == 6)
    {
        if (arg1 == "-rn")
        {
            string path1(arg[3]);
            string path2(arg[5]);

            Rename rename(path1, path2);
            op = &rename;
            op->doOperation();
        }
        else
        {
            string path1(arg[3]);
            string path2(arg[5]);
            Copy cpy(path1, path2);
            op = &cpy;
            op->doOperation();
        }
    }

    return 0;
}