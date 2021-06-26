//
// Created by Jonny Keane on 6/22/21.
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

    int n;
    cin >> n;
//    n = 10000;
    int people[n];
    for (int i = 0; i < n; ++i) {
        cin >> people[i];
//        people[i] = 1000000;
    }
    int null = -1;
    int ind = 0;
    int size = n;
    while (size != 1) {
        int opusMovement = (people[ind] - 1) % size;
        for (int i = 0; i < opusMovement; ++i) {
            ++ind;
            if (ind == n) {
                ind = 0;
            }
            while (people[ind] == null) {
                ++ind;
                if (ind == n) {
                    ind = 0;
                }
            }
        }
        people[ind] = null;
        --size;
        while (people[ind] == null) {
            ++ind;
            if (ind == n) {
                ind = 0;
            }
        }
    }
    cout << ind + 1 << endl;
    return 0;
}