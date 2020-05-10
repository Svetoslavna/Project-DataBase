#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "FileLine.h"

using namespace std;

int getUserInput();
void displayDbs();
void addDbLine(string dbName, int amountOfColumns);

list<FileLine> fileLines;

//путь к файлу(вида C:\\Users\\user\\) если нет, то файл создается в папке проекта
string path = "";

//имя файла
string filename = "databases.txt";

int main() {
    string line;
    ifstream in(path + filename); // окрываем файл для чтения

    //читаем файл построчно и записываем в структуру list
    if (in.is_open()) {
        while (getline(in, line)) {
            istringstream iss(line);
            string db;
            int amount;
            //Если структура файла неверна - выводим ошибку
            if (!(iss >> db >> amount)) {
                cout << "Wrong file structure" << endl;
                break;
            }

            //Записываем в лист
            fileLines.push_back(FileLine(amount, db));
        }
        //сортируем list
        fileLines.sort([](FileLine fl1, FileLine fl2) {return fl1.getDbName() < fl2.getDbName(); });
    }
    in.close();

    int userChoice;

    userChoice = getUserInput();

    while (userChoice != 3) {

        switch (userChoice) {
        case 1: {
            displayDbs();
            break;
        }
        case 2: {
            int amountOfColumns;
            string dbName;

            cout << "Enter database name:" << endl;
            cin >> dbName;

            cout << "Enter the amount of columns:" << endl;
            cin >> amountOfColumns;

            addDbLine(dbName, amountOfColumns);

            break;
        }
        default: {

            cout << "Wrong value\n" << endl;
            break;
        }
        }
        userChoice = getUserInput();
    }

    return 0;
}

int getUserInput() {
    string line;
    int input;

    cout << "List of DBs - press 1" << endl;
    cout << "Add new DB line - press 2" << endl;
    cout << "Exit the programm - press 3" << endl;

    if (cin >> input) {
        return input;
    }
    else {
        // invalid number
        cin.clear();
        while (cin.get() != '\n'); // empty loop
        return -1;
    }
}

void displayDbs() {
    ifstream databaseFileInput(path + filename);

    int amountOfColumns;
    string dbName;

    while (databaseFileInput >> dbName >> amountOfColumns) {
        cout << dbName << ' ' << amountOfColumns << endl;
    }
    cout << "\n";
    databaseFileInput.close();
}

void addDbLine(string dbName, int amountOfColumns) {
    fileLines.push_back(FileLine(amountOfColumns, dbName));
    //сортируем список
    fileLines.sort([](FileLine fl1, FileLine fl2) {return fl1.getDbName() < fl2.getDbName(); });

    //открываем поток для записи в файл
    ofstream databaseFileOutput(path + filename);
    list<FileLine>::iterator it;
    //Записываем новый список в файл
    for (it = fileLines.begin(); it != fileLines.end(); ++it) {
        databaseFileOutput << it->getDbName() << " " << it->getAmountOfColumns() << endl;
    }
    databaseFileOutput.close();

}