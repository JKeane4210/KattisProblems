//
// Created by Jonny Keane on 3/14/22.
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

    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    int counts_a[27];
    int counts_b[27];
    for (int i = 0; i < 27; ++i) {
        counts_a[i] = 0, counts_b[i] = 0;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == ' ') {
            counts_a[26]++;
        } else {
            counts_a[a[i] - 'a']++;
        }
    }
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == ' ') {
            counts_b[26]++;
        } else {
            counts_b[b[i] - 'a']++;
        }
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (counts_a[c - 'a'] != 0 && (counts_a[c - 'a'] * 2) == counts_b[c - 'a']) {
            cout << c;
        }
    }
    if (counts_a[26] != 0 && counts_a[26] * 2 == counts_b[26]) {
        cout << ' ';
    }
    cout << endl;

    return 0;
}