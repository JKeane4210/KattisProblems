//
// Created by Jonny Keane on 2/20/22.
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

    int r, q;
    cin >> r >> q;

    vector<ll> row_difs[4502];
    vector<ll> col_difs[4502];
    vector<ll> row_prefs[4502];
    vector<ll> col_prefs[4502];
    for (int i = 0; i < 4502; ++i) {
        row_difs[i] = vector<ll>(4502, 0);
        col_difs[i] = vector<ll>(4502, 0);
        row_prefs[i] = vector<ll>(4502, 0);
        col_prefs[i] = vector<ll>(4502, 0);
    }

    for (int i = 0; i < r; ++i) {
        int x, y, w, h, c;
        cin >> x >> y >> w >> h >> c;
        row_difs[y + 2251][x + 2251] += c;
        row_difs[y + 2251][x + 2251 + w] -= c;
        row_difs[y + 2251 + h][x + 2251] += c;
        row_difs[y + 2251 + h][x + 2251 + w] -= c;

        col_difs[y + 2251][x + 2251] += c;
        col_difs[y + 2251 + h][x + 2251] -= c;
        col_difs[y + 2251][x + 2251 + w] += c;
        col_difs[y + 2251 + h][x + 2251 + w] -= c;
    }

    for (int i = 0; i < 4502; ++i) {
        ll row_sum = 0;
        ll row_curr = 0;
        for (int j = 0; j < 4502; ++j) {
            row_curr += row_difs[i][j];
            row_sum += row_curr;
//            tests[i][j] = row_curr;
            if (i != 0) {
                row_prefs[i][j] += row_prefs[i - 1][j];
            }
            row_prefs[i][j] += row_sum;
        }
    }

    for (int i = 0; i < 4502; ++i) {
        ll col_sum = 0;
        ll col_curr = 0;
        for (int j = 0; j < 4502; ++j) {
            col_curr += col_difs[j][i];
            col_sum += col_curr;
//            tests2[j][i] = col_curr;
            if (i != 0) {
                col_prefs[j][i] += col_prefs[j][i - 1];
            }
            col_prefs[j][i] += col_sum;
        }
    }

//    for (int i = -2; i <= 5; ++i) {
//        for (int j = -2; j <= 5; ++j) {
//            cout << row_prefs[i + 2251][j + 2251] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (int i = -2; i <= 5; ++i) {
//        for (int j = -2; j <= 5; ++j) {
//            cout << tests[i + 2251][j + 2251] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (int i = -2; i <= 5; ++i) {
//        for (int j = -2; j <= 5; ++j) {
//            cout << col_prefs[i + 2251][j + 2251] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    for (int i = -2; i <= 5; ++i) {
//        for (int j = -2; j <= 5; ++j) {
//            cout << tests2[i + 2251][j + 2251] << " ";
//        }
//        cout << endl;
//    }

    for (int i = 0; i < q; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        if (w == 0 || h == 0) {
            cout << 0 << endl;
            continue;
        }
        ll total = row_prefs[y + 2251 + h][x + 2251 + w - 1] + col_prefs[y + 2251 + h - 1][x + 2251 + w];
        total += row_prefs[y + 2251 - 1][x + 2251 - 1] + col_prefs[y + 2251 - 1][x + 2251 - 1];
        total -= row_prefs[y + 2251 + h][x + 2251 - 1] + col_prefs[y + 2251 + h - 1][x + 2251 - 1]; // "left" section
        total -= row_prefs[y + 2251 - 1][x + 2251 + w - 1] + col_prefs[y + 2251 - 1][x + 2251 + w]; // "above" section
//        cout << total << endl;
//        cout << row_prefs[y + 2251 + h - 1][x + 2251 - 1] + col_prefs[y + 2251 + h - 1][x + 2251 - 2] << endl;
//        cout << row_prefs[y + 2251 - 2][x + 2251 + w - 1] + col_prefs[y + 2251 - 1][x + 2251 + w - 1] << endl << endl;
        cout << total << endl;
    }

    return 0;
}
