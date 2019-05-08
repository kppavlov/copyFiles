#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <string>
using namespace std;

class Operations
{
public:
  Operations();

  ~Operations();

  void virtual doOperation() = 0;

  void setPathFrom(char *from);
  void setPathTo(char *to);

private:
  string pathFrom;
  string pathTo;
  string operation;
};
#endif