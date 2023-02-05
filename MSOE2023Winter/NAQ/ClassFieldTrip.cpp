//
// Created by keanej on 2/4/2023.
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

    string s1, s2;
    cin >> s1 >> s2;
    int p1 = 0;
    int p2 = 0;
    while (p1 < s1.length() || p2 < s2.size()) {
        if (p1 < s1.length() && p2 < s2.length()) {
            if (s1[p1] < s2[p2]) {
                cout << s1[p1++];
            } else {
                cout << s2[p2++];
            }
        } else if (p1 < s1.length()) {
            cout << s1[p1++];
        } else {
            cout << s2[p2++];
        }
    }
    cout << endl;

    return 0;
}
