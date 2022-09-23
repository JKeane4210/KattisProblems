//
// Created by keanej on 9/17/2022.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string ns;
    while (getline(cin, ns)) {
        long n = stol(ns);
        string line;
        getline(cin, line);
        map<string, long> counts;
        while (line != "EndOfText") {
            transform(line.begin(), line.end(), line.begin(),
                      [](unsigned char c) { return tolower(c); });
            string curr_word;
            for (char c: line) {
                if (c >= 'a' && c <= 'z') {
                    curr_word += c;
                } else if (!curr_word.empty()) {
                    counts[curr_word]++;
                    curr_word = "";
                }
            }
            if (!curr_word.empty()) {
                counts[curr_word]++;
            }
            getline(cin, line);
        }

        bool one_word_found = false;
        for (const auto &p: counts) {
            if (p.second == n) {
                cout << p.first << endl;
                one_word_found = true;
            }
        }
        if (!one_word_found) {
            cout << "There is no such word." << endl;
        }
    }

    return 0;
}