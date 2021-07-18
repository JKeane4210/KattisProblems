//
// Created by Jonny Keane on 7/17/21.
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

    string s;
    cin >> s;
    int n = s.size();
    int *vals = (int *)malloc(n * sizeof(n));
    int *altVals = (int * )malloc(n * sizeof(n));
    memset(vals, 0, n * sizeof(int));
    memset(altVals, 0, n * sizeof(int));
    for (int  i= 0; i < n; ++i) {
        vals[i] = stoi(s.substr(i, 1));
    }
    bool done = false;
    int roundNum = 0;
    while (!done) {
        memset(altVals, 0, n * sizeof(int));
//        cout << roundNum++ << ": ";
        for (int i = 0; i < n; ++i) {
            cout << vals[i];
        }
        cout << endl;
        done = true;
        for (int i = 0; i < n; ++i) {
            altVals[i] += vals[i];
            if (vals[i] >= 2) {
                done = false;
                altVals[i] -= 2;
                if (i - 1 >= 0) {
                    ++altVals[i - 1];
                }
                if (i + 1 < n) {
                    ++altVals[i + 1];
                }
            }
        }
        int * temp = vals;
        vals = altVals;
        altVals = temp;
    }
    for (int i = 0; i < n; ++i) {
        cout << vals[i];
    }
    cout << endl;

    return 0;
}