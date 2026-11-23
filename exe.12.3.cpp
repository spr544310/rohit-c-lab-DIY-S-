#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    int product = accumulate(v.begin(), v.end(), 1,
        [](int a, int b) {
            return a * b;
        });

    int sum = accumulate(v.begin(), v.end(), 0,
        [](int a, int b) {
            return (b % 2 == 0) ? a + b : a;
        });

    cout << "Product of all elements = " << product << endl;
    cout << "Sum of even elements = " << sum << endl;

    return 0;
}