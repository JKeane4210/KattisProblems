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

int maxDig(bitset<200> dugUp, const bitset<200>* obstructedBy, const int* valDelta, int level, int max_, int total, int n) {
    if (level == n) {
        return max_;
    }
    int localMax = -INT_MAX;
    vector<int> localMaxInds;
    for (int j = 0; j < n; ++j) {
        if ((obstructedBy[j] & ~dugUp).none() && !dugUp[j]) {
            if (valDelta[j] > localMax) {
                localMax = valDelta[j];
                localMaxInds.clear();
                localMaxInds.push_back(j);
            } else if (valDelta[j] == localMax) {
                localMaxInds.push_back(j);
            }
        }
    }
    for (int localMaxInd: localMaxInds) {
        bitset<200> nextStep(dugUp);
        nextStep[localMaxInd] = true;
        max_ = max(max_, maxDig(nextStep, obstructedBy, valDelta, level + 1,
                             max(max_, total + localMax), total + localMax, n));
    }
    return max_;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
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
    cout << maxDig(bitset<200>(), obstructedBy, valDelta, 0, 0, 0, n) << nl;
    return 0;
}