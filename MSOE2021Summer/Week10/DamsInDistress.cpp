//
// Created by Jonny Keane on 7/25/21.
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

struct Dam {
public:
    int capacity = INT_MAX;
    int water = INT_MAX;
    vector<int> children;
    Dam() {
        children = vector<int>();
    }
    void init(int c, int w) {
        capacity = c;
        water = w;
    }
};

int min_ = INT_MAX;

void minDfs(int waterNeeded, int node, const Dam* dams) { // prior to adding node
    if (node != 0) {
        waterNeeded = max(waterNeeded - dams[node].water, dams[node].capacity - dams[node].water);
        min_ = min(min_, waterNeeded);
//        printf("Dam %i -> Cap Needed: %i \n", node, waterNeeded);
    }
    for (int child: dams[node].children) {
        minDfs(waterNeeded, child, dams);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    Dam dams[n + 1];
    for (int i = 1; i <= n; ++i) {
        int d, c, u;
        cin >> d >> c >> u;
        dams[i].init(c, u);
        dams[d].children.__emplace_back(i);
    }

    minDfs(w, 0, dams);
    cout << min(min_, w) << endl;

    return 0;
}
