//
// Created by Jonny Keane on 9/3/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

void solve() {
    int r, c;
    cin >> r >> c;
    string matrix[r];
    int conns[r][c];
    for (int i = 0; i < r; ++i) {
        cin >> matrix[i];
        for (int j = 0; j < c; ++j) {
            conns[i][j] = 0;
        }
    }
    int one_count = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (matrix[i][j] == '1') {
                ++one_count;
                for (int k = 0; k < r; ++k) {
                    if (k == i) continue;
                    conns[k][j] |= 0b1;
                }
                for (int k = 0; k < c; ++k) {
                    if (k == j) continue;
                    conns[i][k] |= 0b10;
                }
            }
        }
    }
    if (one_count == 1) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << ((matrix[i][j] == '1') ? 'P' : 'N');
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0;j < c; ++j) {
            if (matrix[i][j] == '1') {
                if (conns[i][j] == 0b1 || conns[i][j] == 0b10) {
                    matrix[i][j] = 'P';
                } else if (conns[i][j] == 0b11) {
                    matrix[i][j] = 'I';
                } else {
                    matrix[i][j] = 'N';
                }
            } else {
                if (conns[i][j] == 0b11) {
                    cout << "impossible" << endl;
                    return;
                }
                matrix[i][j] = 'N';
            }
        }
    }
    for (const string& line: matrix) {
        cout << line << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
        cout << string(10, '-') << endl;
    }

    return 0;
}