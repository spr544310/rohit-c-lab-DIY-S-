#include <iostream>
using namespace std;

// Template function to swap values
template <class T>
void swapVals(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Template function to find maximum
template <class T>
T findMax(T arr[], int n)
{
    T maxVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    return maxVal;
}

int main()
{
    int a = 10, b = 20;

    cout << "Before swapping: " << a << " " << b << endl;
    swapVals(a, b);
    cout << "After swapping: " << a << " " << b << endl;

    int arr[] = {10, 50, 30, 20};
    cout << "Maximum integer: " << findMax(arr, 4) << endl;

    double x = 10.5, y = 20.5;
    swapVals(x, y);

    cout << "After swapping double: " << x << " " << y << endl;

    double arr2[] = {10.5, 25.5, 15.5};
    cout << "Maximum double: " << findMax(arr2, 3);

    return 0;
}