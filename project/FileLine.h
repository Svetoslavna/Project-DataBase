#ifndef FILELINE_H
#define FILELINE_H

#include <string>
using namespace std;

class FileLine
{
public:
    FileLine();
    FileLine(int amount, string name);
    void setAmountOfColumns(int amount);
    void setDbName(string name);
    int getAmountOfColumns();
    string getDbName();

protected:

private:
    int amountOfColumns;
    string dbName;
};

#endif // FILELINE_H
