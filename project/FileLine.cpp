#include "FileLine.h"

using namespace std;
FileLine::FileLine()
{
    amountOfColumns = 0;
    dbName = "";
}
FileLine::FileLine(int amount, string name)
{
    amountOfColumns = amount;
    dbName = name;
}
void FileLine::setAmountOfColumns(int amount) {
    amountOfColumns = amount;
}
int FileLine::getAmountOfColumns() {
    return(amountOfColumns);
}
void FileLine::setDbName(string name) {
    dbName = name;
}
string FileLine::getDbName() {
    return(dbName);
}