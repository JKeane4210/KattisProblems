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
    pair<pair<string, int>, pair<string, int>> nameInfo[n];
    string folders[n];
    for (int i = 0; i < n; ++i) {
        string first, last;
        cin >> first >> last;
        transform(first.begin(), first.end(), first.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        transform(last.begin(), last.end(), last.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        names[i] = last + first;
        nameInfo[i] = make_pair(make_pair(first, 1), make_pair(last, 1));
        folders[i] = last.substr(0, 1) + first.substr(0, 1);
    }
    sort(names, names + n);
    sort(folders, folders + n);

    return 0;
}