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
// passed by reference
Copy::Copy(char *&pathFrom, char *&pathTo)
{
    string path1(pathFrom);
    string path2(pathTo);

    pathFr = path1;
    pathDest = path2;
}
// passed by value
// Copy::Copy(char *pathFrom, char *pathTo)
// {
//     string path1(pathFrom);
//     string path2(pathTo);

//     pathFr = path1;
//     pathDest = path2;
// }

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
