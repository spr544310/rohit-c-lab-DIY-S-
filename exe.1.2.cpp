#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s1, s2;

    cout << "Enter first word: ";
    cin >> s1;

    cout << "Enter second word: ";
    cin >> s2;

    for (char &ch : s1)
        ch = tolower(static_cast<unsigned char>(ch));

    for (char &ch : s2)
        ch = tolower(static_cast<unsigned char>(ch));

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 == s2)
        cout << "The words are anagrams." << endl;
    else
        cout << "The words are not anagrams." << endl;

    return 0;
}