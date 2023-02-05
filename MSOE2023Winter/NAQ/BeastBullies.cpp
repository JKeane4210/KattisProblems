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
    
    int n;
    cin >> n;
    ll animals[n];
    for (int i = 0; i < n; ++i) {
        cin >> animals[i];
    }
    sort(animals, animals + n);

    ll attack = animals[n - 1];
    ll defense = 0;

    ll nDefenders = 0;
    ll total = 1;

    for (int i = n - 2; i >= 0; --i) {
//        cout << animals[i] << endl;
        defense += animals[i];
        nDefenders++;

        if (defense >= attack) {
            attack += defense;
            total += nDefenders;

            defense = 0;
            nDefenders = 0;
        }
    }
    cout << total << endl;
    
    return 0;
}