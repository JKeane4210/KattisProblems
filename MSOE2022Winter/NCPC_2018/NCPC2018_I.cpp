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

int add_counter = 0;

bool cmp(string & a, string & b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

bool cmp_bid(pair<string, string>& a, pair<string, string>& b) {
    return cmp(a.second, b.second);
}

string string_add(string a, string b) {
    ++add_counter;
//    cout << a << " + " << b;
    string res;
    if (a.length() < b.length()) {
        swap(a, b);
    }
    int carry = 0;
    for (int i = 0; i < a.length(); ++i) {
        int dig_res = a[a.length() - 1 - i] - '0' + carry;
        if (i < b.length()) {
            dig_res += b[b.length() - 1 - i] - '0';
        }
        if (dig_res < 10) {
            res.append(to_string(dig_res));
            carry = 0;
        } else {
            res.append(to_string(dig_res % 10));
            carry = dig_res / 10;
        }
    }
    if (carry != 0) {
        string carry_s = to_string(carry);
        reverse(carry_s.begin(), carry_s.end());
        res.append(carry_s);
    }
    reverse(res.begin(), res.end());
//    cout << " = " << res << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    vector<pair<string, string>> bids;
    for (int i = 0; i < n; ++i) {
        string name, bid;
        cin >> name >> bid;
        bids.pb(make_pair(name, bid));
    }

    set<int> winners;
    sort(bids.begin(), bids.end(), cmp_bid);
    queue<pair<string, set<int>>> q;
    for (int i = 0; i < bids.size(); ++i) {
        if (cmp(bids[i].second, s)) {
            set<int> e;
            e.insert(i);
            q.push(make_pair(bids[i].second, e));
        }
    }
    set<int> curr_group;
    string sum = "0";
    for (int i = n - 1; i >= 0; --i) {
        string poss_sum = string_add(sum, bids[i].second);
        if (poss_sum == s) {
            curr_group.insert(i);
            winners = curr_group;
            break;
        }
        if (cmp(poss_sum, s)) {
            sum = poss_sum;
            curr_group.insert(i);
        }
    }
    cout << winners.size() << endl;
    for (int i: winners) {
        cout << bids[i].first << endl;
    }
//    cout << add_counter << " adds" << endl;

    return 0;
}