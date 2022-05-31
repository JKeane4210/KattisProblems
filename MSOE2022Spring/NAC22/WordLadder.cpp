//
// Created by team15 on 5/30/22.
//

#include <bits/stdc++.h>
using namespace std;

bool print(int * counters, int & n) {
    for (int i = 0; i < 6; ++i) {
        cout << (char)('a' + counters[i]);
    }
    cout << endl; --n;
    return n == 0;
}

int main(){
    int n;
    cin >> n;

    int counters[6];
    fill(counters, counters + 6, 0);

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 25- i; ++j) {
            for (int k = 0; k < 25 - i - j; ++k) {
                counters[0]++;
                if (print(counters, n)) return 0;
                counters[1]++;
                if (print(counters, n)) return 0;
            }
            counters[2]++;
            if (print(counters, n)) return 0;
            counters[3]++;
            if (print(counters, n)) return 0;
            counters[0] = 0;
            if (print(counters, n)) return 0;
            counters[1] = 0;
            if (print(counters, n)) return 0;
        }
        counters[4]++;
        if (print(counters, n)) return 0;
        counters[5]++;
        if (print(counters, n)) return 0;
        counters[2] = 0;
        if (print(counters, n)) return 0;
        counters[3] = 0;
        if (print(counters, n)) return 0;
    }

    return 0;
}