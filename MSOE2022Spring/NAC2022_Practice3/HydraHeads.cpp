//
// Created by keanej on 5/19/2022.
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

int min_moves(int h, int t) {
    if (t == 0 && h % 2 == 1) return -1;
    int move_count = 0;
    if (t % 2 == 1) {
        ++move_count;
        ++t;
    }
    while ((h + t / 2) % 2 == 1 || t % 2 == 1) {
        ++t;
        ++move_count;
    }
    move_count += t / 2;
    h += t / 2;
    return move_count + h / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, t;
    cin >> h >> t;
    while (h != 0 || t != 0) {
        cout << min_moves(h, t) << endl;
        cin >> h >> t;
    }

    return 0;
}