//
// Created by Jonny Keane on 6/27/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    string grid[r][c];
    int toRemove = 0;
    for (int i = 0; i < r; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < c; ++j) {
            grid[i][j] = line[j];
            if (grid[i][j] == ".") {
                grid[i][j] = "..";
            } else {
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                    grid[i][j] = ".1";
                } else {
                    ++toRemove;
                }
            }
        }
    }

    int deltas[4][2] = { {0, 1} , {0, -1}, {1, 0}, {-1, 0} };
    int layer = 0;
    while (toRemove != 0) {
        string trigger = layer == 0 ? ".." : layer < 10 ? "." + to_string(layer) : to_string(layer);
        string target = layer + 1 < 10 ? "." + to_string(layer + 1) : to_string(layer + 1);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == "T") {
                    for (auto & delta : deltas) {
                        int deltaR = i + delta[0];
                        int deltaC = j + delta[1];
                        if (deltaR >= 0 && deltaC >= 0 && deltaR < r && deltaC < c && grid[deltaR][deltaC] == trigger) {
                            grid[i][j] = target;
                            --toRemove;
                            break;
                        }
                    }
                }
            }
        }
        ++layer;
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (layer >= 10) {
                cout << ".";
            }
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}