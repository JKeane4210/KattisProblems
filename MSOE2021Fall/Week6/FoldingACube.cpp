//
// Created by Jonny Keane on 10/12/21.
//

//3 * 4 somewhere
// just want the 4 one way in the middle and 3 the other way
// can have the edge case of one shifted

// even further, I just need the T

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

    string grid[6];
    for (int i = 0; i < 6; ++i) {
        cin >> grid[i];
    }
    int max_r = -1, min_r = 7;
    int max_c = -1, min_c = 7;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (grid[i][j] == '#') {
                max_r = max(max_r, i);
                min_r = min(min_r, i);
                max_c = max(max_c, j);
                min_c = min(min_c, j);
            }
        }
    }
    if ((max_r - min_r == 3 && max_c - min_c == 2) || (max_r - min_r == 2 && max_c - min_c == 3)) {
        if (max_c - min_c == 2) {
            int mid_col = min_c + 1;
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (grid[i][mid_col] == '#') {
                    ++count;
                }
            }
            if (count >= 3) {
                cout << "can fold" << endl;
                return 0;
            } else if (count == 2) {
                int count_min = 0;
                int count_max = 0;
                for (int i = 0; i < 6; ++i) {
                    if (grid[i][min_c] == '#') {
                        ++count_min;
                    }
                    if (grid[i][max_c] == '#') {
                        ++count_max;
                    }
                }
                if (count_min == 2 && count_max == 2) {
                    cout << "can fold" << endl;
                    return 0;
                }
            }
        } else {
            int mid_row = min_r + 1;
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (grid[mid_row][i] == '#') {
                    ++count;
                }
            }
            if (count >= 3) { // handles the stair case
                cout << "can fold" << endl;
                return 0;
            } else if (count == 2) {
                int count_min = 0;
                int count_max = 0;
                for (int i = 0; i < 6; ++i) {
                    if (grid[min_r][i] == '#') {
                        ++count_min;
                    }
                    if (grid[max_r][i] == '#') {
                        ++count_max;
                    }
                }
                if (count_min == 2 && count_max == 2) {
                    cout << "can fold" << endl;
                    return 0;
                }
            }
        }
    }
    if ((max_r - min_r == 4 && max_c - min_c == 1) || (max_r - min_r == 1 && max_c - min_c == 4)) {
        if (max_c - min_c == 1) {
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (grid[i][min_c] == '#') {
                    ++count;
                }
            }
            if (count == 3) {
                cout << "can fold" << endl;
                return 0;
            }
        } else {
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (grid[min_r][i] == '#') {
                    ++count;
                }
            }
            if (count == 3) {
                cout << "can fold" << endl;
                return 0;
            }
        }
    }
    cout << "cannot fold" << endl;
    //   #  # #   ###
    // ###  # ###  #

    // fails on:
    // ###
    //  #
    //  ##

    // so maybe needs to be 4 by 3 and hav the T
    return 0;
}