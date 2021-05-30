//
// Created by Jonny Keane on 5/28/21.
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

    int A1, m;
    cin >> A1 >> m;
    unordered_set<int> sequence;
    unordered_set<int> differences;
    sequence.insert(A1);
    int An = A1;
    int d = 1;
    int n = 1;

    while (sequence.count(m) == 0 && differences.count(m) == 0) {
        ++n;
        while (sequence.count(d) != 0 || differences.count(d) != 0) {
            ++d;
        }
        An = An + d;
        for (int i: sequence) {
            differences.insert(An - i);
        }
        sequence.insert(An);
    }
    cout << n << endl;

    return 0;
}