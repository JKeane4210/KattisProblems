//
// Created by Jonny Keane on 6/17/21.
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
    bitset<200> dugUp;
    bitset<200> obstructedBy[n];
    int valDelta[n];
    for (int i = 0; i < n; ++i) {
        int v, c, m;
        cin >> v >> c >> m;
        valDelta[i] = v - c;
        for (int j = 0; j < m; ++j) {
            int block;
            cin >> block;
            obstructedBy[block - 1][i] = true;
        }
    }

    int max = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int localMax = -INT_MAX;
        int localMaxInd = -1;
        for (int j = 0; j < n; ++j) {
            if ((obstructedBy[j] & ~dugUp).none() && !dugUp[j]) {
                if (valDelta[j] > localMax) {
                    localMax = valDelta[j];
                    localMaxInd = j;
                }
            }
        }
        total += localMax;
        dugUp[localMaxInd] = true;
        if (total > max) {
            max = total;
        }
    }
    cout << max << endl;

    return 0;
}