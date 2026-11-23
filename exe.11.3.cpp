#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> freq;
    string word;

    cout << "Enter words (Ctrl+D to stop):" << endl;

    while (cin >> word) {
        freq[word]++;
    }

    cout << "\nWord Frequencies:\n";

    string maxWord;
    int maxCount = 0;

    for (auto x : freq) {
        cout << x.first << " : " << x.second << endl;

        if (x.second > maxCount) {
            maxCount = x.second;
            maxWord = x.first;
        }
    }

    if (!freq.empty()) {
        cout << "\nMost Frequent Word: " << maxWord << endl;
        cout << "Count: " << maxCount << endl;
    }

    return 0;
}