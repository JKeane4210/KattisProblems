//
// Created by Jonny Keane on 5/31/21.
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
    const int MAX_SIZE = 100;
    int m, n, k;
    cin >> m >> n >> k;
    bitset<MAX_SIZE> sets[m];
    for (int i = 0; i < m; ++i) {
        bitset<MAX_SIZE> set;
        for (int j = 0; j < n; ++j) {
            int next;
            cin >> next;
            if (next == 0) {
                set[j] = true;
            }
        }
        sets[i] = set;
    }

    int canHold = 0;
    for (int i = 0; i < k; ++i) {
        int maxNew = 0;
        bitset<MAX_SIZE> max;
        for (auto set: sets) {
            if (set.count() > maxNew) {
                maxNew = set.count();
                max = set;
            }
        }
        if (maxNew == 0) break;
        canHold += maxNew;
        for (int j = 0; j < m; ++j) {
            sets[j] &= ~max;
        }
    }
//    cout << canHold << endl;
    cout << (canHold == n ? "yes" : "no") << endl;

    return 0;
}