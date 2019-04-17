#include "fsOperations.hpp"
#include <iostream>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;

// Rename::Rename(char *pathToFile, char *newPathToFile)
// {
//     string path1(pathToFile);hiy
//     string path2(newPathToFile);
//     oldPath = path1;
//     newPath = path2;
// }

Rename::Rename(char *&pathToFile, char *&newPathToFile)
{
    string path1(pathToFile);
    string path2(newPathToFile);
    oldPath = path1;
    newPath = path2;
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

void Rename::rename()
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