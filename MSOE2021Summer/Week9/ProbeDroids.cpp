//
// Created by Jonny Keane on 7/18/21.
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

struct Droid {
public:
    int x, y;
    double angle;
    Droid(int x, int y) : x(x), y(y), angle(atan((double)(y - 1) / (x - 1))) {}
    bool operator<( const Droid& other ) const {
        if (angle == other.angle) return x + y < other.x + other.y;
        return angle < other.angle;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    map<double, int> angleCounts;
    vector<Droid> droids;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            if (x == 1 && y == 1) continue;
            droids.emplace_back(x, y);
            double angle = atan((double)(y - 1) / (x - 1));
            if (angleCounts.find(angle) == angleCounts.end()) {
                angleCounts[angle] = 0;
            }
            ++angleCounts[angle];
        }
    }
    for (auto p: angleCounts) {
        cout << p.first << ": " << p.second << endl;
    }
    cout << angleCounts.size() << endl;
    sort(droids.begin(), droids.end());
    for (int i = 0; i < q; ++i) {
        long query;
        cin >> query;
        Droid res = droids[query - 1];
        cout << res.y << " " << res.x << endl;
    }

    return 0;
}