//
// Created by Jonny Keane on 1/18/22.
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

bool is_in(char c) {
    return (c >= 'A' && c <= 'Z') || c <= 1;
}

bool get_op(char c, const vector<bool>& in) {
    if (c <= 1) {
        return c;
    } else {
        return in[c - 'A'];
    }
}

bool eval(const vector<char>& ops, int start, int end, const vector<bool>& in, int n) {
    vector<char> curr_ops(ops);
    while (curr_ops.size() != 1) {
        vector<char> new_ops;
        for (int i = 0; i < curr_ops.size(); ++i) {
            if (i < curr_ops.size() - 1) {
                if (is_in(curr_ops[i])) {
                    if (curr_ops[i + 1] == '-') {
                        new_ops.emplace_back(!get_op(curr_ops[i], in));
                        ++i;
                        continue;
                    }
                }
            }
            if (i < curr_ops.size() - 2) {
                if (is_in(curr_ops[i]) && is_in(curr_ops[i + 1])) {
                    if (curr_ops[i + 2] == '*') {
                        new_ops.emplace_back(get_op(curr_ops[i], in) & get_op(curr_ops[i + 1], in));
                        i += 2;
                        continue;
                    }
                    if (curr_ops[i + 2] == '+') {
                        new_ops.emplace_back(get_op(curr_ops[i], in) | get_op(curr_ops[i + 1], in));
                        i += 2;
                        continue;
                    }
                }
            }
            new_ops.emplace_back(curr_ops[i]);
        }
        curr_ops = new_ops;
//        for (char op: curr_ops) {
//            if (op <= 1) {
//                cout << (int)op << " ";
//            } else {
//                cout << op << " ";
//            }
//        }
//        cout << endl;
    }
    return get_op(curr_ops[0], in) == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> in(4);
    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        in[i] = c[0] == 'T';
    }
    vector<char> ops;
    string op;
    while (cin >> op) {
        ops.pb(op[0]);
    }
    bool res = eval(ops, 0, ops.size() - 1, in, n);
    cout << (res ? 'T' : 'F') << endl;
    return 0;
}