#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int total = 0;
mutex m;

void add() {
    for (int i = 0; i < 100000; i++) {
        lock_guard<mutex> lock(m);
        total++;
    }
}

int main() {
    thread t1(add);
    thread t2(add);

    t1.join();
    t2.join();

    cout << "Final Total = " << total << endl;

    return 0;
}