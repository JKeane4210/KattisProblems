#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    bitset<26 * 5> yellows;
    char known[5];
    pair<int, bool> char_states[26];
    for (int i = 0; i < 5; ++i) {
        known[i] = 0;
    }
    for (int i = 0; i < 26; ++i) {
        char_states[i] = make_pair(0, false);
    }
    for (int i = 0; i < n; ++i) {
        string guess, resp; cin >> guess >> resp;
        int counts[26];
        for (int j = 0; j < 26; ++j) {
            counts[j] = 0;
        }
        for (int j = 0; j < 5; ++j) {
            if (resp[j] == '-') {
                char_states[guess[j] - 'A'].second = true;
            } else if (resp[j] == 'G' || resp[j] == 'Y') {
                ++counts[guess[j] - 'A'];
                if (resp[j] == 'Y') {
                    yellows[(guess[j] - 'A') * 5 + j] = true;
                } else {
                    known[j] = guess[j];
                }
            }
        }
        for (int j = 0; j < 26; ++j) {
            char_states[j].first = max(char_states[j].first, counts[j]);
        }
    }
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 26; ++j) {
//            cout <<
//        }
//    }
    for (int i = 0; i < w; ++i) {
        string guess; cin >> guess;
        int counts[26];
        for (int j = 0; j < 26; ++j) {
            counts[j] = 0;
        }
        bool valid = true;
        for (int j = 0; j < 5; ++j) {
            ++counts[guess[j] - 'A'];
            if (known[j] != 0 && guess[j] != known[j]) {
                valid = false;
            }
            if (yellows[(guess[j] - 'A') * 5 + j]) {
                valid = false;
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (char_states[j].second && counts[j] != char_states[j].first) {
                valid = false;
            } else if (!char_states[j].second && counts[j] < char_states[j].first) { // if don't know max amount but don't have enough
                valid = false;
            }
        }
        if (valid) {
            cout << guess << endl;
        }
    }
    return 0;
}
