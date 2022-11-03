#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    cin >> word;
    int alpha[26] = {0};
    int max = 0;
    char letter;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] < 'a') {
            alpha[word[i] - 'A']++;
        } else {
            alpha[word[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] > max) {
            max = alpha[i];
            letter = 'A' + i;
        } else if (alpha[i] == max) {
            letter = '?';
        }
    }
    
    cout << letter;
}