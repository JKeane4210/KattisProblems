//
// Created by Jonny Keane on 5/21/22.
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

    int n;
    cin >> n;
    int c1[n];
    int c2[n];
    for (int i = 0; i < n; ++i) {
        cin >> c1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c2[i];
    }
    sort(c1, c1 + n);
    int deltas[n];
    for (int i = 0; i < n; ++i) {
        deltas[i] = c1[(i + 1) % n] - c1[i];
        if (deltas[i] < 0) deltas[i] += 360000;
//        cout << deltas[i] << " ";
    }
//    cout << endl;
    sort(c2, c2 + n);
    int deltas2[n];
    for (int i = 0; i < n; ++i) {
        deltas2[i] = c2[(i + 1) % n] - c2[i];
        if (deltas2[i] < 0) deltas2[i] += 360000;
//        cout << deltas2[i] << " ";
    }
//    cout << endl;
    int prefixLen[n + 1];
    fill(prefixLen, prefixLen + n + 1, 0);
    prefixLen[0] = -1;
    int i = 1;
    int curr_len = 0;
    while (i < n) {
        // if you match up to this length, increase the length
        if (deltas2[curr_len] == deltas2[i]) {
            curr_len++;
            i++;
            prefixLen[i] = curr_len;
        }
        // otherwise, set the prefix length to the longest prefix length that was seen
        else if (curr_len > 0) {
            curr_len = prefixLen[curr_len];
        }
        // in the case of not having matched before, just reset to the beginning
        else {
            i++;
            prefixLen[i] = 0;
        }
    }
    int t = 0;
    int p = 0;
    while (t < 2 * n) {
        if (deltas2[p % n] == deltas[t % n]) {
            ++t;
            ++p;
//            cout << p << endl;
            if (p == n) {
                cout << "possible" << endl;
                return 0;
            }
        } else {
            p = prefixLen[p];
            if (p < 0) {
                ++t;
                ++p;
            }
        }
    }
    cout << "impossible" << endl;

    return 0;
}