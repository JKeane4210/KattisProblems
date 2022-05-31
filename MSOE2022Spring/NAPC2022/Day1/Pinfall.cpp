//
// Created by keanej on 5/27/2022.
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

// intervals are inclusive
class LazySegmentTree {
public:
    pair<pii, pii> * data;
    int size;

    LazySegmentTree(size_t n) {
        size = 1;
        while (size < n) { size <<= 1; }
        data = (pair<pii, pii> *)malloc((2 * size) * sizeof(pair<pii, pii>));
        memset(data, 0, (2 * size) * sizeof(pair<pii, pii>));
    }

    void update_range(size_t a, size_t b, pii x) {
        update_range(a, b, x, 1, 0, size - 1);
    }

    void update_range(size_t a, size_t b, pii x, int tree_ind, int left, int right) {
        if (b < left || a > right) return;
        if (a <= left && right <= b) {
            if (tree_ind < size) {
                if (x.second > data[tree_ind].second.second) {
                    data[tree_ind].second = x;
                }
            } else {
                if (x.second > data[tree_ind].first.second) {
                    data[tree_ind].first = x;
                }
            }
            return;
        }
        if (x.second > data[tree_ind].first.second) {
            data[tree_ind].first = x;
        }
        int middle = (left + right) / 2;
        update_range(a, b, x, 2 * tree_ind, left, middle);
        update_range(a, b, x, 2 * tree_ind + 1, middle + 1, right);
    }

    pii query(size_t a) {
        return query(a, 1, 0, size - 1, mp(-INT_MAX, -INT_MAX));
    }

    pii query(size_t a, size_t tree_ind, int left, int right, pii lazy) {
        if (tree_ind < size) {
            if (lazy.second > data[tree_ind].second.second) {
                data[tree_ind].second = lazy;
            }
        } else {
            if (lazy.second > data[tree_ind].first.second) {
                data[tree_ind].first = lazy;
            }
        }
        int d = (left + right) / 2;
        lazy = data[tree_ind].second;
        data[tree_ind].first = lazy;
        pii l = query(a, b, 2 * tree_ind, left, d, lazy);
        pii r = query(a, b, 2 * tree_ind + 1, d + 1, right, lazy);
        return l.second > r.second ? l : r;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LazySegmentTree seg(2000001);
    int n;
    cin >> n;
    vector<int> lines[n];
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) {
            lines[i] = {x2, y2, x1, y1};
        } else {
            lines[i] = {x1, y1, x2, y2};
        }
    }

    sort(lines, lines + n, [](const vector<int> & a, const vector<int> & b) {
        return a[1] < b[1];
    });

    for (int i = 0; i < n;++i) {
        seg.update_range(lines[i][0] + 1000000, lines[i][1] + 1000000, mp(lines[i][0], lines[i][3]));
    }

    int x;
    cin >> x;
    cout << seg.query(x + 100000, x + 1000000).first << endl;

    return 0;
}

