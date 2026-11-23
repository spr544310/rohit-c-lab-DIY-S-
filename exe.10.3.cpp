#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    Student s[100];
    int n = 0;

    ifstream fin("student.txt");

    if (!fin) {
        cout << "File not found";
        return 0;
    }

    while (n < 100 &&
           getline(fin, s[n].name, ',')) {
        if (!(fin >> s[n].marks))
            break;

        fin.ignore();
        n++;
    }

    fin.close();

    if (n == 0) {
        cout << "No records found";
        return 0;
    }

    int topper = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[topper].marks)
            topper = i;
    }

    cout << "Topper Details" << endl;
    cout << "Name: " << s[topper].name << endl;
    cout << "Marks: " << s[topper].marks << endl;

    return 0;
}