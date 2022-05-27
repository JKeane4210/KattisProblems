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

    int vals[8];
    for (int i = 0; i < 8; ++i) {
        cin >> vals[i];
        vals[i] *= 2;
    }
    int p1 = (vals[0] + (vals[1] - vals[0]) / 2) + (vals[2] + (vals[3] - vals[2]) / 2);
    int p2 = (vals[4] + (vals[5] - vals[4]) / 2) + (vals[6] + (vals[7] - vals[6]) / 2);
    if (p1 == p2) {
        cout << "Tie" << endl;
    } else if (p1 > p2) {
        cout << "Gunnar" << endl;
    } else {
        cout << "Emma" << endl;
    }


    return 0;
}