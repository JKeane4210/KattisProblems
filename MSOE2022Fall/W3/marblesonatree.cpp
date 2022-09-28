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

const int MAX = 10000;

vi tree[MAX];
int subtree_total[MAX];
int subtree_nodes[MAX];
int marbles[MAX];
bool visited[MAX];
int moves = 0;

void populate_subtotals(int node) {
    int subtotal = marbles[node];
    int subtree_node = 1;
    for (auto conn: tree[node]) {
        if (visited[conn]) continue;
        visited[conn] = true;
        populate_subtotals(conn);
        subtotal += subtree_total[conn];
        subtree_node += subtree_nodes[conn];
    }
    subtree_nodes[node] = subtree_node;
    subtree_total[node] = subtotal;
}

// what do I do when deciding what to take
// the nodes from? how do I know that I am getting the right nodes?
// --> it comes from the recursion
//       ?
//    1     ?
//  2  0   ?  ?
//      3
void calc_min_moves(int node) {
    for (auto conn: tree[node]) {
        if (visited[conn]) continue;
        visited[conn] = true;
        if (subtree_total[conn] > subtree_nodes[conn]) {
            // move from subtree to root
            int diff = subtree_total[conn] - subtree_nodes[conn];
//            cout << diff << " too many marbles in subtree " << conn + 1 << endl;
            moves += diff;
            marbles[node] += diff;
            marbles[conn] -= diff;
            calc_min_moves(conn);
        } else {
            // move from root to subtree
            int diff = subtree_nodes[conn] - subtree_total[conn];
//            cout << diff << " too few marbles in subtree " << conn + 1 << endl;
            moves += diff;
            marbles[conn] += diff;
            marbles[node] -= diff;
            calc_min_moves(conn);
        }
    }
}

void solve(int n) {
    moves = 0;
    for (int i = 0; i < n; ++i) {
        subtree_total[i] = n;
        subtree_nodes[i] = 0;
        tree[i] = vi();
        visited[i] = false;
        marbles[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int v; cin >> v; --v;
        int m;
        cin >> m;
        marbles[i] = m;
        int d; cin >> d;
        for (int j = 0; j < d; ++j) {
            int c; cin >> c; --c;
            tree[v].pb(c);
            tree[c].pb(v);
        }
    }
    visited[0] = true;
    populate_subtotals(0);
//    for (int i = 0; i < n; ++i) {
//        cout << marbles[i] << " " << subtree_total[i] << endl;
//    }
    for (int i = 1; i < n; ++i) {
        visited[i] = false;
    }
    calc_min_moves(0);
    cout << moves << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // ideas:
    // - dijkstras of moves to different states
    //  - cons: can go 2^10000 states
    // - tree dp
    //  - cons: I have no idea what kind of dp this would be

    // [2, 1, 0, 1, 3, 0, 0, 2, 0]

    // new idea:
    // - start at node 1, if subtree count > subtree needed, move extras up to node 1
    // - move needed for other subtree into subtree and recurse
    // - count moves
    int n;
    cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }

    return 0;
}