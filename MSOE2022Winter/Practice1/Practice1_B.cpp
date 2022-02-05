//
// Created by Jonny Keane on 1/29/22.
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

struct block {
public:
    int val;
    block * left;
    block * right;
    block(int val) : val(val) {}
};

void solve() {
    int n;
    cin >> n;
    if (n == 0) { return; }
    if (n == 1) {
        cout << "r" << endl;
        return;
    }
    block * left;
    block * right;
    string sequence;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
//        cout << val << endl;
        if (i == 0) {
            left = new block(val);
            sequence += "r";
            continue;
        } else if (i == 1) {
            right = new block(val);
            right->left = left;
            left->right = right;
            sequence += "r";
        } else {
            if (left == right) {
                block * b = new block(val);
                left->right = b;
                b->left = left;
                right = b;
                sequence += "r";
            } else if (val > left->val && val > right->val) {
                cout << "no" << endl;
                return;
            } else if (left->val <= right->val && val <= left->val) {
                block *b = new block(val);
                b->right = left;
                left->left = b;
                left = b;
                sequence += "l";
            } else {
                block *b = new block(val);
                b->left = right;
                right->right = b;
                right = b;
                sequence += "r";
            }
        }
        while (left->right != nullptr && left->val == left->right->val) {
            left = left->right;
            left->val *= 2;
        }
        while (right->left != nullptr && right->val == right->left->val) {
            right = right->left;
            right->val *= 2;
        }
//        cout << sequence << endl;
//        block* curr = left;
//        while (curr != nullptr) {
//            cout << curr->val << " ";
//            curr = curr->right;
//        }
//        cout << endl;
    }
    if (left != right) {
        cout << "no" << endl;
    } else {
        cout << sequence << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }

    return 0;
}