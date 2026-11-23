#include <iostream>
using namespace std;

class Money {
private:
    int rupees, paise;

public:
    Money(int r = 0, int p = 0) {
        int total = r * 100 + p;
        rupees = total / 100;
        paise = total % 100;
    }

    Money operator+(Money m) {
        int total1 = rupees * 100 + paise;
        int total2 = m.rupees * 100 + m.paise;
        int total = total1 + total2;

        return Money(total / 100, total % 100);
    }

    Money operator-(Money m) {
        int total1 = rupees * 100 + paise;
        int total2 = m.rupees * 100 + m.paise;

        if (total1 < total2) {
            cout << "Insufficient amount!" << endl;
            return Money();
        }

        int total = total1 - total2;
        return Money(total / 100, total % 100);
    }

    void display() {
        cout << "Rs. " << rupees << ".";
        if (paise < 10)
            cout << "0";
        cout << paise << endl;
    }
};

int main() {
    Money m1(10, 75);
    Money m2(5, 50);

    Money sum = m1 + m2;
    Money diff = m1 - m2;

    cout << "First amount: ";
    m1.display();

    cout << "Second amount: ";
    m2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}