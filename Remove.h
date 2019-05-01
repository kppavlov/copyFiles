#include <iostream>
#include <string>
#ifndef _OPERATIONS_H
#define _OPERATIONS_H
#include "Operations.h"
#endif
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
