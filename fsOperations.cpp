#include "fsOperations.hpp"
#include <iostream>
#include <string>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

// Default constructor
Copy::Copy()
{
    pathFr = "/home";
    pathDest = "/home";
}

Copy::Copy(char *pathFrom, char *pathTo)
{
    string path1(pathFrom);
    string path2(pathTo);

    pathFr = path1;
    pathDest = path2;
}

// copy constructor
Copy::Copy(const Copy &c)
{
    std::cout << "copy const\n";
};

// destructor
Copy::~Copy()
{
    std::cout << "Copy free some memory\n";
};

void Copy::catchError(const std::exception &e)
{
    std::cout << "----------------------------------\n";
    std::cerr << "ERROR: " << e.what() << "\n";
    std::cout << "----------------------------------\n";
}

void Copy::copy()
{
    try
    {
        fs::copy(pathFr, pathDest);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

// Copy END

Rename::Rename(char *pathToFile, char *newPathToFile)
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

// Rename END

Remove::Remove()
{
    path = "";
}

Remove::Remove(char *pathToFile)
{
    string path1(pathToFile);
    path = path1;
}
Remove::~Remove()
{
    cout << "Remove free up memory\n";
};

void Remove::remove()
{
    try
    {
        fs::remove(path);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}
