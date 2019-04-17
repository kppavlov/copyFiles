#include <string>

using namespace std;

class Copy
{
public:
  // default constructor
  Copy();
  // Copy(char *pathFrom, char *pathTo);
  Copy(char *&pathFrom, char *&pathTo);
  // copy constructor
  Copy(const Copy &c);
  // destructor
  ~Copy();
  void copy();
  void catchError(const std::exception &e);

private:
  string pathFr;
  string pathDest;
};

class Rename
{

public:
  Rename();
  // Rename(char *pathToFile, char *newPath);
  Rename(char *&pathToFile, char *&newPath);
  ~Rename();

  void rename();

private:
  string oldPath;
  string newPath;
};

class Remove
{
public:
  Remove();
  // Remove(char *pathToFile);
  Remove(char *&pathToFile);

  ~Remove();

  void remove();

private:
  string path;
};
