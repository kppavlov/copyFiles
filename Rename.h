#include <iostream>
#include <string>
#ifndef _OPERATIONS_H
#define _OPERATIONS_H
#include "Operations.h"
#endif

using namespace std;

class Rename : public Operations
{

public:
  Rename();
  Rename(string pathToFile, string newPath);
  ~Rename();

  void doOperation();

private:
  string oldPath;
  string newPath;
};
