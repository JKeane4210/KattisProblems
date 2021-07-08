//
// Created by Jonny Keane on 6/16/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string names[n];
    int inds[n];
    pair<pair<string, int>, pair<string, int>> nameInfo[n]; // first, n, last, n
//    map<string, string> namesToFolders;
    map<string, vector<string>> folderPossibilities;
    for (int i = 0; i < n; ++i) {
        inds[i] = 0;
        string first, last;
        cin >> first >> last;
        transform(first.begin(), first.end(), first.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        transform(last.begin(), last.end(), last.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        names[i] = last + first;
        nameInfo[i] = make_pair(make_pair(first, 1), make_pair(last, 1));
        vector<string> folderPoss;
        for (int j = 1; j <= last.size(); ++j) {
            folderPoss.push_back(last.substr(0, j) + first.substr(0, 1));
        }
        for (int j = 2; j <= first.size(); ++j) {
            folderPoss.push_back(last + first.substr(0, j));
        }
        folderPossibilities[names[i]] = folderPoss;
//        namesToFolders[names[i]] = last.substr(0, 1) + first.substr(0, 1);
    }
    sort(names, names + n);
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        vector<string> left = folderPossibilities[names[i]];
        vector<string> right = folderPossibilities[names[i + 1]];
        int j = 0;
        while (left[inds[i]] >= right[inds[i + 1]]) {
            if (j++ % 2 == 1) {
                ++inds[i];
            } else {
                ++inds[i + 1];
            }
        }
        res += inds[i];
    }
    res += inds[n - 1];
    cout << res << endl;

    return 0;
}