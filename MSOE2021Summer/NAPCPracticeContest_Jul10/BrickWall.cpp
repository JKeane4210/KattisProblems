//
// Created by Jonny Keane on 7/10/21.
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

set<int> layer;

bool canBuild(int sum, int length, int c1, int c2, int c3) {
    if (length > sum) return false;
    if (c1 == -1 || c2 == -1 || c3 == -1) return false;
    if (length == sum) return true;
    if (layer.count(length) != 0) return false;
    if (canBuild(sum, length + 1, c1 - 1, c2, c3)) {
        return true;
    } else if (canBuild(sum, length + 2, c1, c2 - 1, c3)) {
        return true;
    } else {
        return canBuild(sum, length + 3, c1, c2, c3 - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, c1, c2, c3;
    cin >> N >> c1 >> c2 >> c3;
    int sum = 0;
    int maxConsec = 0;
    int numConsec = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            ++numConsec;
        } else {
            maxConsec = max(numConsec, maxConsec);
            numConsec = 0;
        }
        sum += x;
        layer.insert(sum);
    }
    maxConsec = max(numConsec, maxConsec);

    if (c1 + c2 * 2 + c3 * 3 >= sum && maxConsec < 3 && canBuild(sum, 0, c1, c2, c3)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}