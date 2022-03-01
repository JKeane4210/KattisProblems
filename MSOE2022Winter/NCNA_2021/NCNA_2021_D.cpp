//
// Created by Jonny Keane on 2/28/22.
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

    string s;
    cin >> s;
    int vals[4];
    for (int i = 0; i < 4; ++i) {
        vals[i] = s[i] - 0x30;
    }
    for (int i = 3; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (vals[j] & 1 << i) {
                cout << '*';
            } else {
                cout << '.';
            }
            if (j == 1) {
                cout << "  ";
            }
            if (j != 3) {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}