#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long total = 0;
    long start = 0;
    for (int i = 0; i < n; ++i) {
        long x;
        cin >> x;
        total += x;
        if (total < 0) {
            start = max(start, -total);
        }
    }
    cout << start << endl;
}