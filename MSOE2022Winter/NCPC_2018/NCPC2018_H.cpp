//
// Created by Jonny Keane on 2/16/22.
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

    vector<string> cheapest;
    int cheapest_price = INT_MAX;
    int l, n;
    cin >> l >> n;
    for (int i = 0; i< n; ++i) {
        string in;
        getline(cin, in);
        string name;
        name = in.substr(0, in.find(','));
        in.erase(0, in.find(',') + 1);
        cout << name << endl;
        cout << in  << endl;
        int p, c, t, r;
        string p_s = in.substr(0, in.find(','));
        cout << p_s.length() << endl;
//        p = stoi(p_s); // why does this not work????
//        cout << stoi(p_s) << endl;
//        cout <<  << endl;
//        p = stoi(in.substr(0, in.find(','))); in.erase(0, in.find(',') + 1);
//        c = stoi(in.substr(0, in.find(','))); in.erase(0, in.find(',') + 1);
//        t = stoi(in.substr(0, in.find(','))); in.erase(0, in.find(',') + 1);
//        r = stoi(in);
//        cout << name << p << c << t << r << endl;
//        if (l * (t + r) / c <= 10080) {
//            if (p < cheapest_price) {
//                cheapest_price = p;
//                cheapest.clear();
//                cheapest.pb(name);
//            } else if (p == cheapest_price) {
//                cheapest.pb(name);
//            }
//        }
    }
    if (cheapest.empty()) {
        cout << "no such mower" << endl;
    } else {
        for (string mower: cheapest) {
            cout << mower << endl;
        }
    }

    return 0;
}