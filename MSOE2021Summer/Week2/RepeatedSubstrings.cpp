//
// Created by Jonny Keane on 6/1/21.
//

#include <bits/stdc++.h>

#include <utility>

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

//struct Node {
//    public:
//        explicit Node(string s) : s(s), isRepeated(false), left(nullptr), right(nullptr) {};
//        string s;
//        bool isRepeated;
//        Node* left;
//        Node* right;
//};

void solve(string s) {
    int repeats = 0;
    vector<string> paths;
    multiset<string> subs;
//    Node root("");
//    paths.push_back(&root);
    for (char c: s) {
        paths.emplace_back("");
        for (int j = 0; j < paths.size(); ++j) {
            if (subs.count(paths[j] + c) == 1) {
                ++repeats;
            }
            subs.insert(paths[j] + c);
            paths[j] += c;
        }
    }
    cout << repeats << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}