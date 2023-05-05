//
// Created by keanej on 4/23/2023.
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

char * green;
int * need_n;
bool * max_found;
char * ans;
int * yellow_block;

bool search(int l, int i) {
    if (i == l) {
        for (int j = 0; j < 26; ++j) {
            if (need_n[j] > 0) return false;
        }
        return true;
    }
    if (green[i]) {
        ans[i] = green[i];
        return search(l, i + 1);
    } else {
        for (int j = 0; j < 26; ++j) {
            if (need_n[j] > 0 && (yellow_block[i] & (1 << j)) == 0) {
                need_n[j]--;
                ans[i] = (char)('a' + j);
                if (search(l, i + 1)) return true;
                need_n[j]++;
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (need_n[j] <= 0 && !max_found[j] && (yellow_block[i] & (1 << j)) == 0) {
                need_n[j]--;
                ans[i] = (char)('a' + j);
                if (search(l, i + 1)) return true;
                need_n[j]++;
            }
        }
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int g, l;
    cin >> g >> l;
    pair<string, string> pairs[g - 1];
    for (int i = 0; i < g -1; ++i) {
        string a, b;
        cin >> a >> b;
        pairs[i] = {a, b};
    }

    need_n = (int *)calloc(26, sizeof(int));
    green = (char *)calloc(l, sizeof(int));
    max_found = (bool *)calloc(26, sizeof(bool));
    yellow_block = (int *)calloc(l, sizeof(int));

    for (auto p: pairs) {
        int count[26] = {0};
        for (int i = 0; i < 26; ++i) count[i] = 0;
        for (int i = 0; i < l; ++i) {
            if (p.second[i] == 'G') {
                green[i] = p.first[i];
                count[p.first[i] - 'a']++;
            } else if (p.second[i] == 'Y') {
                count[p.first[i] - 'a']++;
                yellow_block[i] |= 1 << (p.first[i] - 'a');
            } else { // 'B'
                max_found[p.first[i] - 'a'] = true;
            }
            need_n[p.first[i] - 'a'] = max(need_n[p.first[i] - 'a'], count[p.first[i] - 'a']);
        }
    }

    for (int i = 0; i < l; ++i) {
        if (green[i])
            need_n[green[i] - 'a'] -= 1;
    }
    ans = (char *)calloc(l + 1, sizeof(char));
    search(l, 0);
    cout << ans << endl;
//    for (int i = 0; i < l; ++i) {
//        if (green[i]) cout << green[i];
//        else {
//            cout << '_';
//            for (int j = 0; j < 26; ++j) {
//
//            }
//        }
//    } cout << endl;
//
//    for (int i = 0; i < 26; ++i) {
//        cout << (char)('a' + i) << " " << need_n[i] << " " << max_found[i] << endl;
//    }

    return 0;
}



/*
 *
 *     int valid[l];
    for (int i = 0; i < l; ++i) {
        valid[i] = (1 << 26) - 1; // correct?
    }
 *
 * bool yellows[26][l];
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < l; ++j) {
            yellows[i][j] = false;
        }
    }
 * else if (p.second[i] == 'Y') {
                valid[i] &= ~(1 << (p.first[i] - 'a'));
                if (!yellows[p.first[i] - 'a'][i]) {
                    yellows[p.first[i] - 'a'][i] = true;
                    need.pb(p.first[i]);
                }
            } else {
                for (int j = 0; j < l; ++j) {
                    valid[j] = ~(1 << (p.first[i] - 'a'));
                }
            }
 */