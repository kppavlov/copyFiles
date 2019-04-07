#include "copyFiles.hpp"
#include <iostream>
#include <string>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int argLen;
char **val;

void Copy::readArgs(int argNum, char **argVal)
{
    argLen = argNum;
    val = argVal;
}

void Copy::copy()
{
    // cast char to string
    std::string arg1(val[1]);
    std::string arg2(val[3]);

    if (arg1 == "-h" || arg1 == "--help" || arg1 != "-i")
    {
        drawHelp();
    }
    else if (arg2 != "-o")
    {
        drawHelp();
    }
    else
    {
        fs::copy(val[2], val[4]);
    }
}

void Copy::catchError(const std::exception &e)
{
    std::cout << "----------------------------------\n";
    std::cerr << "ERROR: " << e.what() << "\n";
    std::cout << "----------------------------------\n";
    drawHelp();
}

void Copy::drawHelp()
{
    std::cout << "Help\n";
    std::cout << "-i path to file or directory to copy\n";
    std::cout << "-o path to directory to paste\n";
    std::cout << "-h || --help to print this help\n";
}
