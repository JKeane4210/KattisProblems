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

set<int> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, s, t;
    cin >> N >> s >> t;
    bool flights[N][N];
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        for (int j = 0; j < N; ++j) {
            flights[i][j] = c == 'C';
        }
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int dest;
            cin >> dest;
            flights[i][dest] = c == 'N';
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        visited.insert(top.first);
        if (top.first == t) {
            cout << top.second << endl;
            return 0;
        }
        for (int i = 0; i < N; ++i) {
            if (flights[top.first][i] && visited.count(i) == 0) {
                q.push(make_pair(i, top.second + 1));
            }
        }
    }
    cout << "impossible" << endl;

    return 0;
}