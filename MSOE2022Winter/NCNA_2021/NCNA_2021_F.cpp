//
// Created by Jonny Keane on 3/1/22.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

class PModInt {
public:
    int i;
    int mod;

    PModInt(int i_, int mod_ = 1000000007) {
        i = i_ % mod_;
        mod = mod_;
    }

    PModInt() : PModInt(0) {}

    PModInt(PModInt const &p) : PModInt(p.i, p.mod) {}

    PModInt operator+ (int a) {
        return PModInt((i + a) % mod, mod);
    }
    PModInt inline operator+ (PModInt pModInt) {
        return *this + pModInt.i;
    }
    PModInt operator* (int a) {
        i = (i * a) % mod;
        return *this;
    }
    PModInt inline operator* (PModInt pModInt) {
        return *this * pModInt.i;
    }
    PModInt operator/ (PModInt pModInt) {
        int c = pModInt.modInv();
        return *this * c;
    }
    PModInt inline operator/ (int a) {
        return *this / PModInt(a, mod);
    }
    string toString() {
        return to_string(i);
    }
    int modInv() {
        return pow(mod - 2);
    }

private:
    int pow(int n) {
        if (n == 0) return 1;
        int p = pow(n / 2) % mod;
        p = (p * p) % mod;
        return (n % 2 == 0) ? p : (i * p) % mod;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string p, s;
    cin >> p >> s;
//    p = string(100000, 'a'); s = "aaaa";
    set<string> poss_s;
    for (int i = 0; i < s.size(); ++i) {
//        cout << s.substr(i, s.size() - i) + s.substr(0, i) << endl;
        poss_s.insert(s.substr(i, s.size() - i) + s.substr(0, i));
    }

    PModInt puzzle_count;
    for (string curr_s: poss_s) {
        PModInt dp[s.size()][p.size()];

//        cout << curr_s << endl;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size() - (s.size() - 1 - i); ++j) {
                if (i > 0) {
                    if (j > 0) {
                        if (p[j] == curr_s[i]) {
                            dp[i][j] = PModInt(dp[i][j - 1] + dp[i - 1][j - 1]);
                        } else {
                            dp[i][j] = PModInt(dp[i][j - 1]);
                        }
                    }
                } else {
                    if (p[j] == curr_s[i]) {
                        if (j > 0) {
                            dp[i][j] = PModInt(dp[i][j - 1] + 1);
                        } else {
                            dp[i][j] = PModInt(1);
                        }
                    } else {
                        if (j > 0) {
                            dp[i][j] = PModInt(dp[i][j - 1]);
                        }
                    }
                }
//                cout << dp[i][j].toString() << " ";
            }
//            cout << endl;
        }
//        cout << endl;
        puzzle_count = PModInt(puzzle_count + dp[s.size() - 1][p.size() - 1]);
    }
    cout << puzzle_count.toString() << endl;

    return 0;
}