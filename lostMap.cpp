//
// Created by Jonny Keane on 4/8/21.
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

struct connection {
    int a;
    int b;
    int dist;

    friend bool operator<(const connection& a, const connection& b);
};

bool operator<(const connection& a, const connection& b) {
    return a.dist < b.dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // code here
    int n;
    cin >> n;
    int adj[n][n];
    set<int> visited;
    visited.insert(0);
    vector<connection> connections;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
            if (i < j) {
                connection con{};
                con.a = i;
                con.b = j;
                con.dist = adj[i][j];
                connections.push_back(con);
            }
        }
    }
//    sort(connections.begin(), connections.end());
//
//    for (int i = 0; i < n - 1; ++i) {
//        pair<int, int> minPair;
//        for (auto top: connections) {
//            if (visited.count(top.a) != 0) {
//                if (visited.count(top.b) == 0) {
//                    minPair = {top.a, top.b};
//                    visited.insert(minPair.second);
//                    break;
//                }
//            } else {
//                if (visited.count(top.b) != 0) {
//                    minPair = {top.a, top.b};
//                    visited.insert(minPair.first);
//                    break;
//                }
//            }
//        }
//        cout << minPair.first + 1 << " " << minPair.second + 1 << nl;
//    }

    return 0;
}