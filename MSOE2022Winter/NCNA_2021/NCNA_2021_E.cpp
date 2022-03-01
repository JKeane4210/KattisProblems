//
// Created by Jonny Keane on 2/28/22.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

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

int deltas[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
//    r = 8, c = 8;
    int grid[r][c];
    int counts[3] = {0, 0, 0};
    pii last_0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
//            grid[i][j] = (i == 0 && j == 0) ? 1 : 2;
            cin >> grid[i][j];
            ++counts[grid[i][j]];
            if (grid[i][j] == 0) {
                last_0 = mp(i, j);
            }
        }
    }
//    cout << count_0 << " " << count_2 << endl;
    if (counts[0] >= 2) {
        cout << 0 << endl;
    } else if (counts[0] == 1) {
        if (r == 1 || c == 1) {
            if (last_0 == mp(0, 0)) {
                cout << grid[r - 1][c - 1] << endl;
            } else if (last_0 == mp(r - 1, c - 1)) {
                cout << grid[0][0] << endl;
            } else {
                cout << min(grid[0][0], grid[r - 1][c - 1]) << endl;
            }
        } else {
            if (counts[1] > 0) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    } else if (counts[0] == 0) {
        if (counts[2] % 2 == 0) {
            cout << 0 << endl;
        } else {
//            cout << count_2 / 2 << endl;
            unsigned long p_low = 1l << (counts[2] / 2);
            cout << p_low << endl;
        }
    }


    return 0;
}
