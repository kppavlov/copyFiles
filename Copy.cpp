#include "Copy.h"
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

//passed by value
Copy::Copy(string pathFrom, string pathTo)
{
    pathFr = pathFrom;
    pathDest = pathTo;
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

void Copy::doOperation()
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
