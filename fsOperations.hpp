#include <string>
class Copy
{
public:
  void readArgs(int argNum, char **argVal);
  void copy();
  void catchError(const std::exception &e);
  void drawHelp();

private:
  int x;
  std::string b;
};
