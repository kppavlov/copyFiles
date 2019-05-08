#include <iostream>
#include <string>
#include "Operations.h"

using namespace std;

class Remove : public Operations
{
public:
  Remove();
  Remove(string pathToFile);

  ~Remove();

  void doOperation();

private:
  string path;
};
