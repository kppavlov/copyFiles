#include <string>
using namespace std;
class FsOperations
{
public:
  // default constructor
  FsOperations();
  FsOperations(string op, string pathFrom, string pathTo);
  // copy constructor
  FsOperations(const FsOperations &c);
  // destructor
  ~FsOperations();
  void copy();
  void catchError(const std::exception &e);
  void drawHelp();
  void whatToDo(string op);
  void rename();
  void remove();

private:
  string operation;
  string pathFr;
  string pathDest;
};
