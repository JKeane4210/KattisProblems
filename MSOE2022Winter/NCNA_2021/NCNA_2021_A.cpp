//
// Created by Jonny Keane on 3/1/22.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int highestOneBit(int i) {
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - (((unsigned int)i) >> 1);
}

struct FenwickTree{
    vector<int> arr;
    int n;

    FenwickTree(int size) {
        int hob = highestOneBit(size);
        n = (hob == size) ? hob : (hob << 1);
        arr.assign(n,0);
    }

    int sum(int k){
        int s = 0;
        int ik = k+1;
        while(ik>=1){
            s+=arr[ik-1];
            ik-= ik & -ik;
        }
        return s;
    }

    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void update(int k, int x){
        int ik = k+1;
        while(ik <= n){
            arr[ik-1]+=x;
            ik+= ik & -ik;
        }
    }
};

vector<FenwickTree> trees;

bool is_even(int a, int b) {
    for (auto tree: trees) {
        if ((tree.sum(a, b) & 1) == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int q;
    cin >> q;

    for (int i = 0; i < 6; ++i) {
        trees.emplace_back(FenwickTree(s.size()));
    }
    for (int i = 0; i < s.size(); ++i) {
        trees[s[i] - 'a'].update(i, 1);
    }
    // track even/odd -> don't match == even
    // a:1110
    // b:0100
    //   abba

    for (int k = 0; k < q; ++k) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int res = 0;
            for (int i = l; i <= r; ++i) {
                for (int j = i; j <= r; ++j) {
                    if (is_even(i, j)) {
                        ++res;
                    }
                }
            }
            cout << res << endl;
        } else {
            int i;
            string x;
            cin >> i >> x;
            --i;
            trees[s[i] - 'a'].update(i, -1);
            trees[x[0] - 'a'].update(i, 1);
            s[i] = x[0];
//            cout << i << "->" << x << endl;
//            for (auto tree: trees) {
//                cout << tree.sum(0, s.size() - 1) << endl;
//            }
//            cout << "*" << endl;
        }
    }

    return 0;
}