#include <iostream>
using namespace std;

class Counter {
private:
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter() {
        totalCreated++;
        currentlyAlive++;
    }

    ~Counter() {
        currentlyAlive--;
    }

    static void showCount() {
        cout << "Total objects created: "
             << totalCreated << endl;
        cout << "Currently alive: "
             << currentlyAlive << endl;
    }
};

// Definition of static members
int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter c1, c2;

    Counter::showCount();

    {
        Counter c3, c4;
        cout << "\nInside block:" << endl;
        Counter::showCount();
    }

    cout << "\nAfter block:" << endl;
    Counter::showCount();

    return 0;
}