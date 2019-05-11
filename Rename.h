#ifndef RENAME_H
#define RENAME_H
#include <iostream>
#include <string>
#include "Operations.h"

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
#endif
