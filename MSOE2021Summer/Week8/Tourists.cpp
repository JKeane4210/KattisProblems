//
// Created by Jonny Keane on 7/12/21.
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

struct Step {
public:
    int curr;
    int prev;
    bitset<200001> visited;
    Step(int curr, int prev, bitset<200001> visited) : curr(curr), prev(prev), visited(visited) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> conns[n + 1];
    bitset<200001> paths[n + 1];
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        conns[a].push_back(b);
        conns[b].push_back(a);
    }
    queue<Step> q;
    q.push(Step(1, 1, bitset<200001>()));
    while (!q.empty()) {
        Step top = q.front();
        q.pop();
        top.visited[top.curr] = true;
        paths[top.curr] = top.visited;
        for (int conn: conns[top.curr]) {
            if (conn != top.prev) {
                q.push(Step(conn, top.curr, bitset<200001>(top.visited)));
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            res += (int)((paths[i] ^ paths[j]).count()) + 1;
        }
    }
    cout << res << endl;
    return 0;
}