#include <string>
#ifndef _OPERATIONS_H
#define _OPERATIONS_H
#include "Operations.h"
#endif

using namespace std;

class Copy : public Operations
{
public:
  // default constructor
  Copy();
  Copy(string pathFrom, string pathTo);
  // copy constructor
  Copy(const Copy &c);
  // destructor
  ~Copy();
  void doOperation();

private:
  string pathFr;
  string pathDest;
};
