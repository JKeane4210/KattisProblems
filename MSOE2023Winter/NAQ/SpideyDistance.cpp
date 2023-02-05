//
// Created by keanej on 2/4/2023.
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

ll spidey(ll s) {
    ll res = 0;
    ll delta = 1;
    for (int i = 0; i < s; ++i) {
        res += delta;
        delta++;
        if (i % 3 == 1) {
            delta++;
        }
    }
    return res * 4 + 1;
}

ll taxi(ll t) {
    return (t * (t + 1) / 2) * 4 + 1;
}

ll gcd(ll p, ll q) {
if (p < 0) return gcd(-p, q);
else if (q < 0) return gcd(p, -q);
else if (p == 0ll) return q;
else if (q == 0ll) return p;
else if ((p & 1ll) == 0ll && (q & 1ll) == 0ll) return gcd(p >> 1, q >> 1) << 1;
else if ((p & 1ll) == 0ll) return gcd(p >> 1, q);
else if ((q & 1ll) == 0ll) return gcd(p, q >> 1);
else if (p > q) return gcd((p - q) >> 1, q);
else return gcd(p, (q - p) >> 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t, s;
    cin >> t >> s;

//    if (t <= s) {
//        ll sp = spidey(s);
//        ll tx = taxi(t);
//        ll g = gcd(min(sp, tx), max(sp, tx));
//        cout << tx / g << "/" << sp / g << endl;
//    } else if (t > s && t <= s * 4 / 3) {
//        raise(SIGSEGV);
//    } else {
//        cout << 1 << endl;
//    }
    ll tRes = 0;
    ll sRes = 0;
    ll tDiag = t / 2;
    ll sDiag = s * 2 / 3; // / 3 / 2
//    cout << sDiag << " " << tDiag << endl;
    for (ll i = 1; i <= max(tDiag, sDiag); ++i) {
//        cout << i << " " <<  ((i * 3 + 1) / 2) << " " << (i * 2) << endl;
        ll s_i = s - ((i * 3 + 1) / 2); // s if you were to move to (i, i)
        ll t_i = t - (i * 2); // t if you were to move to (i, i)
//        cout << i << " " << s_i << " " << t_i << endl << endl;
        if (s_i < 0) {
            continue;
        }
        if (t_i < 0) {
            sRes += s_i;
            continue;
        }
        if (s_i >= t_i) {
            sRes += s_i;
            tRes += t_i;
        } else {
            sRes += s_i;
            tRes += s_i;
        }
//        cout << i << " " << sRes << " " << tRes << endl;
    }
    sRes *= 8;
    tRes *= 8;
    if (s >= t) {
        tRes += t * 4;
        sRes += s * 4;
    } else {
        tRes += s * 4;
        sRes += s * 4;
    }
    if (sDiag >= tDiag) {
        tRes += tDiag * 4;
        sRes += sDiag * 4;
    } else {
        tRes += sDiag * 4;
        sRes += sDiag * 4;
    }
    // the origin
    tRes++;
    sRes++;
    if (tRes == sRes) {
        cout << 1 << endl;
        return 0;
    }
    ll g = gcd(min(tRes, sRes), max(tRes, sRes));
    cout << tRes / g << "/" << sRes / g << endl;

    return 0;
}
