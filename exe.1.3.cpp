#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s, word;
    vector<string> words;

    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);

    while (ss >> word) {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    cout << "Reversed sentence: ";

    for (int i = 0; i < words.size(); i++) {
        cout << words[i];

        if (i < words.size() - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}