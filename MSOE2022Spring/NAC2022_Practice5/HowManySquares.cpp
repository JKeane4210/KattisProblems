//
// Created by Jonny Keane on 5/21/22.
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

bool equals(const pii & a, const pii & b) {
    return (a.first == b.first && a.second == b.second) || (a.first == -b.first && a.second == -b.second);
}

int dot(const pii & a, const pii & b) {
    return a.first * b.first + a.second * b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    pii v[n];
    fill(v, v + n, mp(0, 0));
    bool used[n];
    fill(used, used + n, false);
    map<pii, int> v_counts;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dx = x2 - x1;
        int dy = y2 - y1;
        int gcd_ = gcd(abs(dx), abs(dy));
        if (dx == 0) gcd_ = dy;
        if (dy == 0) gcd_ = dx;
        if (dx < 0 || (dx == 0 && dy < 0)) {
            dx = -dx;
            dy = -dy;
        }
        v[i].first = dx / gcd_, v[i].second = dy / gcd_;
        v_counts[v[i]]++;
    }

    for (auto p : v_counts) {
        cout << p.first.first << " " <<  p.first.second << ": " << p.second << endl;
    }
    // it gets ugly from here :)


    return 0;
}