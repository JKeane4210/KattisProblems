//
// Created by keanej on 5/26/2022.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>
#define wgraph V<V<pii>>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int gcd(int p, int q){
    if(p==0) return q;
    if(q==0) return p;
    if(((p&1)==0) && ((q&1)==0)) return ((gcd(p >> 1, q >> 1)) << 1);
    if((p&1)==0) return gcd(p>>1, q);
    if((q&1)==0) return gcd(p, q>>1);
    if (p>q) return gcd((p-q)>>1, q);
    return gcd(p, (q-p)>>1);
}

pii unit_normal(int dx, int dy) {
    if (dx == 0) {
        return mp(0, 1);
    }
    if (dy == 0) {
        return mp(1, 0);
    }
    int g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
    if (dx < 0) {
        dx = -dx;
        dy = -dy;
    }
    return mp(dx, dy);
}

pii orth(const pii & v) {
    return unit_normal(-v.second, v.first);
}

int dist(const pii & a, const pii & b, const pii & dir) {
    int c1 = a.first * dir.first + a.second * dir.second;
    int c2 = b.first * dir.first + b.second * dir.second;
    return abs(c2 - c1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<pii, vpii> parallels;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        pii normal = unit_normal(x2 - x1, y2 - y1);
        if (parallels.find(normal) == parallels.end()) {
            parallels[normal] = vpii();
        }
        parallels[normal].pb(mp(x1, y1));
    }

    set<pii> seen;
    size_t res = 0;
    for (const auto & p: parallels) {
        unordered_multiset<int> distances;
        pii perp = orth(p.first);
        if (seen.find(p.first) != seen.end()) continue;
        seen.insert(perp);

        for (int i = 0; i < p.second.size(); ++i) {
            for (int j = i + 1; j < p.second.size(); ++j) {
                distances.insert(dist(p.second[i], p.second[j], perp));
            }
        }
        if (parallels.find(perp) != parallels.end()) {
            vpii v = parallels[perp];
            for (int i = 0; i < v.size(); ++i) {
                for (int j = i + 1; j < v.size(); ++j) {
                    res += distances.count(dist(v[i], v[j], p.first));
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}