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

// intervals are inclusive
template<typename E>
class LazySumSegmentTree {
public:
    pair<E, E> * data;
    int n;

    LazySumSegmentTree(int n_) {
        n = 1;
        while (n < n_) { n <<= 1; }
        data = (pair<E, E> *)malloc((2 * n) * sizeof(pair<E, E>));
        memset(data, 0, (2 * n) * sizeof(pair<E, E>));
    }

    void update(int a, int b, int x) {
        update(a, b, x, 1, 0, n - 1);
    }

    void update(int a, int b, int x, int i, int l, int r) {
        if (b < l || a > r) return;
        if (a <= l && r <= b) {
            (i < n ? data[i].second : data[i].first) += x;
            return;
        }
        data[i].first += (min(b, r) - max(l, a) + 1) * x;
        int middle = (l + r) / 2;
        update(a, b, x, i<<1, l, middle);
        update(a, b, x, (i<<1) + 1, middle + 1, r);
    }

    E query(int a, int b) {
        return query(a, b, 1, 0, n - 1, 0);
    }

    E query(int a, int b, int i, int l, int r, int carry) {
        (i < n ? data[i].second : data[i].first) += carry;
        if (b < l || a > r) return 0;
        if (a <= l && r <= b) return data[i].first + (r - l + 1) * data[i].second;
        int d = (l + r) / 2;
        carry = data[i].second;
        data[i].first += (r - l + 1) * data[i].second;
        data[i].second = 0;
        return query(a, b, i<<1, l, d, carry) + query(a, b, (i << 1) + 1, d + 1, r, carry);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    LazySumSegmentTree<ll> seg_tree(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        seg_tree.update(l, r, 1);
    }

    ll vals[n];
    for (int i = 0; i < n; ++i) {
        vals[i] = seg_tree.query(i, i);
//        cout << vals[i] << " ";
    }
//    cout << endl;
    sort(vals, vals + n);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        int lo = 0, hi = n - 1;
        int hit = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vals[mid] < x) {
                lo = mid + 1;
            } else {
                hit = n - mid;
                hi = mid - 1;
            }
        }
        cout << hit << endl;
    }


    return 0;
}