#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int **data;

public:
    Matrix(int m, int n) {
        rows = m;
        cols = n;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols]();
        }
    }

    // Deep copy constructor
    Matrix(const Matrix &other) {
        rows = other.rows;
        cols = other.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    void setValue(int i, int j, int value) {
        data[i][j] = value;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }

        delete[] data;
    }
};

int main() {
    Matrix m1(2, 3);

    m1.setValue(0, 0, 1);
    m1.setValue(0, 1, 2);
    m1.setValue(0, 2, 3);
    m1.setValue(1, 0, 4);
    m1.setValue(1, 1, 5);
    m1.setValue(1, 2, 6);

    cout << "Original Matrix:" << endl;
    m1.display();

    Matrix m2 = m1;

    cout << "Copied Matrix:" << endl;
    m2.display();

    return 0;
}