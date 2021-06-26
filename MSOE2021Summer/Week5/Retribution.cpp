//
// Created by Jonny Keane on 6/23/21.
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

struct Dist {
public:
    int dist;
    int repo;
    int judge;
    Dist(int dist, int repo, int judge) : dist(dist), repo(repo), judge(judge) {};

    friend bool operator<(const Dist &a, const Dist &b) {
        if (a.dist == b.dist) {
            if (a.judge == b.judge) {
                return a.repo > b.repo;
            }
            return a.judge > b.judge;
        }
        return a.dist > b.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    pair<int, int> judges[n];
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        judges[i] = make_pair(x, y);
    }
    double res = 0;
    // tar
    priority_queue<Dist> tar;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < n; ++j) { // judges
            tar.push(Dist((judges[j].first - x)*(judges[j].first - x) + (judges[j].second - y)*(judges[j].second - y), i, j));
        }
    }
    set<int> tarredJudges;
    set<int> tarredLocs;
    while (tarredJudges.size() < n) {
        Dist top = tar.top();
        tar.pop();
        if (tarredJudges.count(top.judge) != 0 || tarredLocs.count(top.repo) != 0) continue;
        tarredJudges.insert(top.judge);
        tarredLocs.insert(top.repo);
        res += sqrt((double)top.dist);
    }
    // feathers
    priority_queue<Dist> feathers;
    for (int i = 0; i < p; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < n; ++j) { // judges
            feathers.push(Dist((judges[j].first-x)*(judges[j].first-x) + (judges[j].second-y)*(judges[j].second-y), i, j));
        }
    }
    set<int> featheredJudges;
    set<int> featheredLocs;
    while (featheredJudges.size() < n) {
        Dist top = feathers.top();
        feathers.pop();
        if (featheredJudges.count(top.judge) != 0 || featheredLocs.count(top.repo) != 0) continue;
        featheredJudges.insert(top.judge);
        featheredLocs.insert(top.repo);
        res += sqrt((double)top.dist);
    }
    printf("%.7f\n", res);

    return 0;
}
