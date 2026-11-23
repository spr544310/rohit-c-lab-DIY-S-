#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Triangle" << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    string name;

    int n;
    cout << "Enter number of shapes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter shape (Circle/Rectangle/Triangle): ";
        cin >> name;

        if (name == "Circle") {
            shapes.push_back(make_unique<Circle>());
        }
        else if (name == "Rectangle") {
            shapes.push_back(make_unique<Rectangle>());
        }
        else if (name == "Triangle") {
            shapes.push_back(make_unique<Triangle>());
        }
        else {
            cout << "Invalid shape!" << endl;
        }
    }

    cout << "\nCreated Shapes:\n";

    for (auto &s : shapes) {
        s->draw();
    }

    return 0;
}