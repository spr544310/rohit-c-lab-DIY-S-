#include <iostream>
using namespace std;

class MathError {
public:
    virtual void display() {
        cout << "Math Error Occurred!" << endl;
    }
};

class DivideByZero : public MathError {
public:
    void display() override {
        cout << "Division by Zero Error!" << endl;
    }
};

int main() {
    DivideByZero d;

    cout << "Correct Catch Order:" << endl;

    try {
        throw d;
    }
    catch (DivideByZero &e) {
        e.display();
    }
    catch (MathError &e) {
        e.display();
    }

    return 0;
}