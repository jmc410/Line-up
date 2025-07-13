#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("LineUp.txt");
    string name;
    string fName, lName;
    int studentCount = 0;

    if (!inputFile) {
        cerr << "Error: Could not open LineUp.txt file." << endl;
        return 1;
    }

    if (inputFile >> name) {
        fName = name;
        lName = name;
        studentCount = 1;
    }

    while (inputFile >> name) {
        studentCount++;

        if (name < fName) {
            fName = name;
        }

        if (name > lName) {
            lName = name;
        }
    }

    inputFile.close();

    if (studentCount == 0) {
        cout << "The file has no names or is empty" << endl;
    } else {
        cout << "Number of students: " << studentCount << endl;
        cout << "Student at the front: " << fName << endl;
        cout << "Student at the end: " << lName << endl;
    }

    return 0;
}