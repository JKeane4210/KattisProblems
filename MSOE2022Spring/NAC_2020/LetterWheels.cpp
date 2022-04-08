//
// Created by Jonny Keane on 3/30/22.
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
#define wgraph V<V<pii>>

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

    string s[3];
    bitset<5001> letters[3][3]; // row, letter
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
//        s[i] = string(5000, i+ 'A');
        for (int j = 0; j < s[i].size(); ++j) {
            letters[i][s[i][j] - 'A'][j] = true;
        }
    }
    int res = INT_MAX;
    int n = s[0].size();

    for (int i = 0; i < n; ++i) {
        bool first_pass = true;
        for (int k = 0; k < 3; ++k) {
            if ((letters[0][k] & letters[1][k]).any()) {
                first_pass = false;
                break;
            }
        }
        if (first_pass) {
            for (int j = 0; j < n; ++j) {
                int poss_res = 0;
                int shift1 = i;
                int shift2 = j;
                if (n - shift1 < shift1) shift1 = -(n - shift1);
                if (n - shift2 < shift2) shift2 = -(n - shift2);
                if (shift1 < 0 && shift2 < 0) {
                    poss_res += min(abs(shift1), abs(shift2));
                    shift1 += poss_res;
                    shift2 += poss_res;
                } else if (shift1 > 0 && shift2 > 0) {
                    poss_res += min(shift1, shift2);
                    shift1 -= poss_res;
                    shift2 -= poss_res;
                }
                if (poss_res + abs(shift1) + abs(shift2) > res) continue;
                bool all_pass = true;
                for (int k = 0; k < 3; ++k) {
                    if ((letters[0][k] & letters[2][k]).any() ||
                        (letters[1][k] & letters[2][k]).any()) {
                        all_pass = false;
                        break;
                    }
                }
                if (all_pass) {
                    res = min(res, poss_res + abs(shift1) + abs(shift2));
                }
                for (int k = 0; k < 3; ++k) { // performs a rotation
                    letters[2][k] <<= 1;
                    letters[2][k][0] = letters[2][k][n];
                    letters[2][k][n] = false;
                }
            }
        }
        for (int j = 0; j < 3; ++j) { // performs a rotation
            letters[1][j] <<= 1;
            letters[1][j][0] = letters[1][j][n];
            letters[1][j][n] = false;
        }
    }
    if (res == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }


    return 0;
}