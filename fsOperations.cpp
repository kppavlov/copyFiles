#include "fsOperations.hpp"
#include <iostream>
#include <string>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

string operation;
string pathFr;
string pathDest;

// Default constructor
FsOperations::FsOperations()
{
    operation = "-c";
    pathFr = "/home";
    pathDest = "/home";
}

FsOperations::FsOperations(string op, string pathFrom, string pathTo)
{
    operation = op;
    pathFr = pathFrom;
    pathDest = pathTo;
}

// copy constructor
FsOperations::FsOperations(const FsOperations &c)
{
    std::cout << "copy const\n";
};

// destructor
FsOperations::~FsOperations()
{
    std::cout << "free some memory\n";
};

void FsOperations::catchError(const std::exception &e)
{
    std::cout << "----------------------------------\n";
    std::cerr << "ERROR: " << e.what() << "\n";
    std::cout << "----------------------------------\n";
    drawHelp();
}

void FsOperations::drawHelp()
{
    std::cout << "Usage\n";
    std::cout << "-operation[-c, -rn, -rm] -input_path[-i /path/do/modify..] -output_path[-o /path/to/paste] \n";
    std::cout << "Help\n";
    std::cout << "-c Copy files/directories\n";
    std::cout << "-rn Rename files/directories\n";
    std::cout << "-rm Remove files/directories\n";
    std::cout << "-i path to file or directory to copy\n";
    std::cout << "-o path to directory to paste\n";
    std::cout << "-h || --help to print this help\n";
}

void FsOperations::whatToDo(string op)
{

    if (op == "-c")
    {
        FsOperations::copy();
    }
    else if (op == "-rn")
    {
        FsOperations::rename();
    }
    else if (op == "-rm")
    {
        FsOperations::remove();
    }
    else
    {
        FsOperations::drawHelp();
    }
}

void FsOperations::rename()
{
    fs::rename(pathFr, pathDest);
}

void FsOperations::remove()
{
    fs::remove(pathFr);
}

void FsOperations::copy()
{
    try
    {
        fs::copy(pathFr, pathDest);
    }
    catch (const std::exception &e)
    {
        FsOperations::catchError(e);
    }
}
