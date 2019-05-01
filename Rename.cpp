#include "Rename.h"
#include <iostream>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;

Rename::Rename(string pathToFile, string newPathToFile)
{
    oldPath = pathToFile;
    newPath = newPathToFile;
}

Rename::Rename()
{
    oldPath = "/home";
    newPath = "/home";
}

Rename::~Rename()
{
    cout << "Rename free up some memory\n";
}

void Rename::doOperation()
{
    try
    {
        fs::rename(oldPath, newPath);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}