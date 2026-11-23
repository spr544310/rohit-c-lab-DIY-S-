#include <iostream>
#include <numeric>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

    void simplify() {
        if (denominator == 0)
            throw invalid_argument("Denominator cannot be zero");

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = d;
        simplify();
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        in >> f.numerator >> f.denominator;

        if (in && f.denominator == 0)
            in.setstate(ios::failbit);
        else if (in)
            f.simplify();

        return in;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    Fraction f;

    cout << "Enter numerator and denominator: ";

    if (cin >> f) {
        cout << "Simplified fraction: " << f << endl;
    } else {
        cout << "Invalid fraction!" << endl;
    }

    return 0;
}