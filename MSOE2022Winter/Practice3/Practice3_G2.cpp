//
// Created by Jonny Keane on 2/20/22.
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

//class SegTree2D {
//    static bool OUT(int l, int r, int ql, int qr) {
//        return (qr < l || ql > r);
//    }
//    static bool IN(int l, int r, int ql, int qr) {
//        return (ql >= l && qr <= r);
//    }
//    long long build_y(int node_x, int lx, int rx, int node_y, int ly, int ry, vector<vector<long long> >& array) {
//        if (ly == ry) {
//            if (lx == rx) {
//                segtree[node_x][node_y] = array[lx][ly];
//            } else {
//                segtree[node_x][node_y] = operation(segtree[node_x * 2 + 1][node_y], segtree[node_x * 2 + 2][node_y]);
//            }
//            return segtree[node_x][node_y];
//        }
//        int my = (ly + ry) / 2;
//        long long left = build_y(node_x, lx, rx, node_y * 2 + 1, ly, my, array);
//        long long right = build_y(node_x, lx, rx, node_y * 2 + 2, my + 1, ry, array);
//        segtree[node_x][node_y] = operation(left, right);
//        return segtree[node_x][node_y];
//    }
//    long long build_x(int node_x, int lx, int rx, vector<vector<long long> >& array) {
//        if (lx != rx) {// demarcs that branching is still possible
//            int mx = (lx + rx) / 2;
//            build_x(node_x * 2 + 1, lx, mx, array);
//            build_x(node_x * 2 + 2, mx + 1, rx, array);
//        }
//        return build_y(node_x, lx, rx, 0, 0, m - 1, array);
//    }
//    long long query_y(int node_x, int node_y, int ly, int ry, int qly, int qry) {
//        if (OUT(qly, qry, ly, ry)) {
//            return def;
//        } else if (IN(qly, qry, ly, ry)) {
//            return segtree[node_x][node_y];
//        }
//        int my = (ly + ry) / 2;
//        long long left = query_y(node_x, node_y * 2 + 1, ly, my, qly, qry);
//        long long right = query_y(node_x, node_y * 2 + 2, my + 1, ry, qly, qry);
//        return operation(left, right);
//    }
//    long long query_x(int node_x, int lx, int rx, int qlx, int qrx, int qly, int qry) {
//        if (OUT(qlx, qrx, lx, rx)) {
//            return def;
//        } else if (IN(qlx, qrx, lx, rx)) {
//            return query_y(node_x, 0, 0, m - 1, qly, qry);
//        }
//        int mx = (lx + rx) / 2;
//        long long left = query_x(node_x * 2 + 1, lx, mx, qlx, qrx, qly, qry);
//        long long right = query_x(node_x * 2 + 2, mx + 1, rx, qlx, qrx, qly, qry);
//        return operation(left, right);
//    }
//    long long update_y(int node_x, int lx, int rx, int node_y, int ly, int ry, int uy, int update_value) {
//        if (uy > ry || uy < ly) {
//            return segtree[node_x][node_y];
//        }
//        if (ly == ry && ly == uy) {
//            if (lx == rx) {
//                segtree[node_x][node_y] = update_value;
//            } else {
//                segtree[node_x][node_y] = operation(segtree[node_x * 2 + 1][node_y], segtree[node_x * 2 + 2][node_y]);
//            }
//            return segtree[node_x][node_y];
//        }
//        int my = (ly + ry) / 2;
//        long long left = update_y(node_x, lx, rx, node_y * 2 + 1, ly, my, uy, update_value);
//        long long right = update_y(node_x, lx, rx, node_y * 2 + 2, my + 1, ry, uy, update_value);
//        segtree[node_x][node_y] = operation(left, right);
//        return segtree[node_x][node_y];
//    }
//    void update_x(int node_x, int lx, int rx, int ux, int uy, long long update_value) {
//        if (ux > rx || ux < lx) {
//            return;
//        }
//        if (lx == rx && lx == ux) {
//            update_y(node_x, lx, rx, 0, 0, m - 1, uy, update_value);
//            return;
//        }
//        int mx = (lx + rx) / 2;
//        update_x(node_x * 2 + 1, lx, mx, ux, uy, update_value);
//        update_x(node_x * 2 + 2, mx + 1, rx, ux, uy, update_value);
//        update_y(node_x, lx, rx, 0, 0, m - 1, uy, update_value);
//    }
//public:
//    SegTree2D(int n, int m, long long def) : def(def), n(n), m(m) {
//        segtree.resize(4 * n, vector<long long>(4 * m));
//    }
//    SegTree2D(vector<vector<long long> >& array, int n, int m, long long def) : def(def), n(n), m(m) {
//        segtree.resize(4 * n, vector<long long>(4 * m));
//        construct(array);
//    }
//    void construct(vector<vector<long long> >& array) {
//        build_x(0, 0, n - 1, array);
//    }
//    long long query(int qlx, int qrx, int qly, int qry) {
//        return query_x(0, 0, n - 1, qlx, qrx, qly, qry);
//    }
//    void update(int ux, int uy, long long update_value) {
//        update_x(0, 0, n - 1, ux, uy, update_value);
//    }
//private:
//    inline static long long operation(long long left, long long right) {
//        return max(left, right);
//    }
//    vector<vector<long long> > segtree;
//    size_t n, m;
//    long long def;
//};

<typename E>
class segment_tree {

public:
    int arr[N];
    int tree[MAX];
    int lazy[MAX];

/**
 * Build and init tree
 */
    void build_tree(int node, int a, int b) {
        if (a > b) return; // Out of range

        if (a == b) { // Leaf node
            tree[node] = arr[a]; // Init value
            return;
        }

        build_tree(node * 2, a, (a + b) / 2); // Init left child
        build_tree(node * 2 + 1, 1 + (a + b) / 2, b); // Init right child

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Init root value
    }

/**
 * Increment elements within range [i, j] with value value
 */
    void update_tree(int node, int a, int b, int i, int j, int value) {

        if (lazy[node] != 0) { // This node needs to be updated
            tree[node] += lazy[node]; // Update it

            if (a != b) {
                lazy[node * 2] += lazy[node]; // Mark child as lazy
                lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
            }

            lazy[node] = 0; // Reset it
        }

        if (a > b || a > j || b < i) // Current segment is not within range [i, j]
            return;

        if (a >= i && b <= j) { // Segment is fully within range
            tree[node] += value;

            if (a != b) { // Not leaf node
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }

            return;
        }

        update_tree(node * 2, a, (a + b) / 2, i, j, value); // Updating left child
        update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value); // Updating right child

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // Updating root with max value
    }

/**
 * Query tree to get max element value within range [i, j]
 */
    int query_tree(int node, int a, int b, int i, int j) {

        if (a > b || a > j || b < i) return -inf; // Out of range

        if (lazy[node] != 0) { // This node needs to be updated
            tree[node] += lazy[node]; // Update it

            if (a != b) {
                lazy[node * 2] += lazy[node]; // Mark child as lazy
                lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
            }

            lazy[node] = 0; // Reset it
        }

        if (a >= i && b <= j) // Current segment is totally within range [i, j]
            return tree[node];

        int q1 = query_tree(node * 2, a, (a + b) / 2, i, j); // Query left child
        int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j); // Query right child

        int res = max(q1, q2); // Return final result

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // code here

    return 0;
}