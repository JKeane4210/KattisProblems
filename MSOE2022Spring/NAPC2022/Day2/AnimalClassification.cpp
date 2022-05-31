//
// Created by keanej on 5/28/2022.
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

ll getHash(const string & s, int left, int right, const vector<ll> & hashes, vector<ll> & res) {
//    cout << s.substr(left, right - left + 1) << endl;
    if (s[left] >= '0' && s[left] <= '9') {
        int num = s[left] - '0';
        while (s[left + 1] >= '0' && s[left + 1] <= '9') {
//            cout << s[left + 1] << endl;
            ++left;
            num *= 10;
            num += s[left] - '0';
        }
        res.pb(hashes[num - 1]);
        if (left == right) {
            return hashes[num - 1];
        } else {
            // +2 to get to the next segment
            ll rightHash = getHash(s, left + 2, right - 1, hashes, res);
            res.pb(hashes[num - 1] ^ rightHash);
        }
    } else { // another nested block
        int nextComma = left;
        int depth = s[nextComma] == '(' ? 1 : 0;
        while (depth != 1 || s[nextComma] != ',') {
            ++nextComma;
            if (s[nextComma] == '(') ++depth;
            if (s[nextComma] == ')') --depth;
        }
//        cout << "left" << endl;
        ll leftHash = getHash(s, left + 1, nextComma - 1, hashes, res);
//        cout << "right" << endl;
        ll rightHash = getHash(s, nextComma + 1, right - 1, hashes, res);
        res.push_back(leftHash ^ rightHash);
        return leftHash ^ rightHash;
    }
}

void getHashes(const string & s, int left, int right, const vector<ll> & hashes, vector<ll> & res) {
    int nextComma = left;
    int depth = s[nextComma] == '(' ? 1 : 0;
    while (depth != 1 || s[nextComma] != ',') {
        ++nextComma;
        if (s[nextComma] == '(') ++depth;
        if (s[nextComma] == ')') --depth;
    }
    ll leftHash = getHash(s, left + 1, nextComma - 1, hashes, res);
    ll rightHash = getHash(s, nextComma + 1, right - 1, hashes, res);
    res.pb(leftHash ^ rightHash);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // good book code for future --> random number generator for longs
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<ll> dist(LONG_LONG_MIN, LONG_LONG_MAX);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    string s1, s2;
    cin >> s1 >> s2;
    vector<ll> hashes(n);
    for (int i = 0; i < n; ++i) {
        hashes[i] = dist(gen);
    }

    vector<ll> hashes1;
    getHashes(s1, 0, s1.size() - 1, hashes, hashes1);

    vector<ll> hashes2;
    getHashes(s2, 0, s2.size() - 1, hashes, hashes2);

    sort(hashes1.begin(), hashes1.end());
    sort(hashes2.begin(), hashes2.end());

//    for (auto hash : hashes1){
//        cout << hash << " ";
//    }
//    cout << endl;
//
//    for (auto hash : hashes2){
//        cout << hash << " ";
//    }
//    cout << endl;

    // assign a random long to each of the numbers 1 ... n
    // parse the tree and generate hash values for each set as the XOR of all elements in the set
    // sort the hashes and find how many matches you have

    int ans = 0;
    int ptr = 0;
    for (int i = 0; i < hashes1.size(); ++i) {
        while (ptr < hashes2.size() && hashes2[ptr] <= hashes1[i]) {
            if (hashes2[ptr] == hashes1[i]) {
                ++ans;
            }
            ++ptr;
        }
    }

    cout << ans << endl;

    return 0;
}