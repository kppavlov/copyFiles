#include "Remove.h"
#include <iostream>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;

Remove::Remove()
{
    path = "";
};

Remove::Remove(string pathToFile)
{
    path = pathToFile;
};

Remove::~Remove()
{
    cout << "Remove free up memory\n";
};

void Remove::doOperation()
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
};
