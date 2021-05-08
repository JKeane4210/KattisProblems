//
// Created by Jonny Keane on 5/7/21.
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

long long result = 0;
vector<int> vars;
vector<bool> use1;

void allConfigurations(int index, string line) {
    if (index == vars.size()) {
        int current1Slide = line.size() - 1;
        int questionInd = vars.size() - 1;
        for (int i = line.size() - 1; i >= 0; --i) {
            if (line[i] == '?') {
                if (use1[questionInd]) {
                    if (current1Slide - i != 0) {
                        result = result + (current1Slide - i);
                    }
                    --current1Slide;
                }
                --questionInd;
            }
            if (line[i] == '1') {
                if (current1Slide - i != 0) {
                    result += current1Slide - i;
                }
                --current1Slide;
            }
        }
    } else {
        use1[index] = true;
        allConfigurations(index + 1, line);
        use1[index] = false;
        allConfigurations(index + 1, line);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    cin >> line;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == '?') {
            vars.pb(i);
            use1.pb(false);
        }
    }

    allConfigurations(0, line);


    cout << result % 1000000007 << endl;
    return 0;
}