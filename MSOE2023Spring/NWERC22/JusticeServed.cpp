//
// Created by keanej on 5/3/2023.
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
#define sz(a) a.size()

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

//struct FT {
//    vector<ll> s;
//    FT(int n) : s(n) {}
//    // 0b11 (3)
//    // 0b11 | 0b100 = 0b111 (7)
//    // 0b101
//    // 0b101 | 0b110 -> fills next bit
//    void update(int pos, ll val) { // a[pos] += dif
//        pos++;
//        for (; pos <= sz(s); pos += pos & (-pos)) s[pos - 1] = max(s[pos - 1], val);
//    }
//    // 0b11 (3)
//    // 0b11 & 0b10 = 0b10 -> clears a bit (1)
//    ll query(int pos) { // sum of values in [0, pos)
//        pos++;
//        ll res = 0;
//        for (; pos >= 1; pos -= pos & (-pos)) res = max(res, s[pos - 1]);
//        return res;
//    }
//};

// inclusive-exclusive?
//const int inf = 0;
//struct Node {
//    Node *l = 0, *r = 0;
//    int lo, hi, mset = inf, madd = 0, val = -inf;
//    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
//    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
//        if (lo + 1 < hi) {
//            int mid = lo + (hi - lo)/2;
//            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
//            val = max(l->val, r->val);
//        }
//        else val = v[lo];
//    }
//    int query(int L, int R) {
//        if (R <= lo || hi <= L) return -inf;
//        if (L <= lo && hi <= R) return val;
//        push();
//        return max(l->query(L, R), r->query(L, R));
//    }
//    void set(int L, int R, int x) {
//        if (R <= lo || hi <= L) return;
//        if (L <= lo && hi <= R) mset = val = x, madd = 0;
//        else {
//            push(), l->set(L, R, x), r->set(L, R, x);
//            val = max(l->val, r->val);
//        }
//    }
//    void add(int L, int R, int x) {
//        if (R <= lo || hi <= L) return;
//        if (L <= lo && hi <= R) {
//            if (mset != inf) mset += x;
//            else madd += x;
//            val += x;
//        }
//        else {
//            push(), l->add(L, R, x), r->add(L, R, x);
//            val = max(l->val, r->val);
//        }
//    }
//    void push() {
//        if (!l) {
//            int mid = lo + (hi - lo)/2;
//            l = new Node(lo, mid); r = new Node(mid, hi);
//        }
//        if (mset != inf)
//            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
//        else if (madd)
//            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
//    }
//};

template<typename E>
class segment_tree {
public:
    pair<E, E> *data;
    int size;

    segment_tree(int n) {
        size = 1;
        while (size < n) { size <<= 1; }
        data = (pair<E, E> *) malloc((2 * size) * sizeof(pair<E, E>));
        memset(data, 0, (2 * size) * sizeof(pair<E, E>));
    }

    void add(int index, int x) {
        index += size;
        data[index].first += x;
        for (index /= 2; index >= 1; index /= 2) {
            data[index].first += x;
        }
    }

    void add_range(int a, int b, int x) {
        add_range(a, b, x, 1, 0, size - 1);
    }

    void add_range(int a, int b, int x, int seg_tree_ind, int seg_tree_ind_left, int seg_tree_ind_right) {
        if (b < seg_tree_ind_left || a > seg_tree_ind_right) return; // if none of the range is encompassed, return
        if (a <= seg_tree_ind_left &&
            seg_tree_ind_right <= b) { // if encompasses whole range, add to all in range and return
            if (seg_tree_ind < size) {
                data[seg_tree_ind].second = max(data[seg_tree_ind].second, x);
            } else {
                data[seg_tree_ind].first = max(data[seg_tree_ind].first, x);
            }
            return;
        }
//        data[seg_tree_ind].first += (min(b, seg_tree_ind_right) - max(seg_tree_ind_left, a) + 1) * x; // add the overlapping section
        int middle =
                (seg_tree_ind_left + seg_tree_ind_right) / 2; // otherwise, add range first half & add range second half
        add_range(a, b, x, 2 * seg_tree_ind, seg_tree_ind_left, middle);
        add_range(a, b, x, 2 * seg_tree_ind + 1, middle + 1, seg_tree_ind_right);
    }

    E sum(int a, int b) {
        return sum(a, b, 1, 0, size - 1, 0); // sum on [a, b] over the range [x, y]
    }

    E sum(int a, int b, int seg_tree_ind, int seg_tree_ind_left, int seg_tree_ind_right, int add_all) {
        if (seg_tree_ind < size) {
            data[seg_tree_ind].second = max(data[seg_tree_ind].second, add_all);
        } else {
            data[seg_tree_ind].first = max(data[seg_tree_ind].first, add_all);
        }
        if (b < seg_tree_ind_left || a > seg_tree_ind_right) return 0; // if none of the range is encompassed, return 0
        if (a <= seg_tree_ind_left && seg_tree_ind_right <= b) {
            return max(data[seg_tree_ind].first, data[seg_tree_ind].second);
//            return data[seg_tree_ind].first + (seg_tree_ind_right - seg_tree_ind_left + 1) * data[seg_tree_ind].second; // if whole range is encompassed, return section
        }
        int d = (seg_tree_ind_left + seg_tree_ind_right) /
                2; // otherwise, return the first half sum + the second half sum
        add_all = data[seg_tree_ind].second;
        data[seg_tree_ind].first = max(data[seg_tree_ind].first, data[seg_tree_ind].second);
//        data[seg_tree_ind].first += (seg_tree_ind_right - seg_tree_ind_left + 1) * data[seg_tree_ind].second;
        data[seg_tree_ind].second = 0;
        return max(sum(a, b, 2 * seg_tree_ind, seg_tree_ind_left, d, add_all),
               sum(a, b, 2 * seg_tree_ind + 1, d + 1, seg_tree_ind_right, add_all));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> intervals;
    set<int> times;
    for (int i = 0; i < n; ++i) {
        int a, t;
        cin >> a >> t;
        intervals.pb({a, a + t, i});
        times.insert(a + t);
    }
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    map<int, int> mappings;
    int ind = 0;
    for (int v: times) {
        mappings[v] = ind++;
    }
    for (int i = 0; i < n; ++i) {
//        cout << intervals[i][0] << " " << intervals[i][1] << " " << mappings[intervals[i][1]] << endl;
        intervals[i][1] = mappings[intervals[i][1]];

    }

    int ans[n];
//    FT ft(16);
    segment_tree<int> seg_tree(times.size());
    for (int i = 0; i < n; ++i) {
//        cout << intervals[i][2] << ": " << ft.query(intervals[i][1]) << endl;
        ans[intervals[i][2]] = 1 + seg_tree.sum(intervals[i][1], intervals[i][1]);
//        for (int j = 0; j < times.size(); ++j) {
//            cout << seg_tree.sum(j, j) << " ";
//        } cout << endl;
        seg_tree.add_range(0, intervals[i][1], ans[intervals[i][2]]);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] - 1 << " ";
    }
    cout << endl;

    return 0;
}

/*
5
1 7
1 6
5 10
5 1
6 1

 */