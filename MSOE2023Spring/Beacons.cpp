//
// Created by keanej on 5/11/2023.
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

struct point {
    ll x, y, mountain;
};

struct mountain {
    ll x, y, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;
    point cities[n];
    mountain peaks[p];
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        cities[i] = {x, y, 0};
    }
    for (int i = 0; i < p; ++i) {
        ll x, y, r;
        cin >> x >> y >> r;
        peaks[i] = {x, y, r};
    }
    double TWO_PI = M_PI * 2;

    int n_components = 0;
    int visited[n];
    for (int i = 0; i < n; ++i) visited[i] = -1;
    for (int i = 0; i < n; ++i) {
        if (visited[i] != -1) continue;
        cout << "*" << i << endl;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            auto top = q.front(); q.pop();
            if (visited[top] != -1) continue;
            visited[top] = n_components;
            cout << top << endl;
            point top_p = cities[top];
            vector<tuple<double, int, int, double>> sweep_points;
            for (int j = 0; j < n; ++j) {
                if (visited[j] != -1) continue;
                double angle = atan2(cities[j].y - top_p.y, cities[j].x - top_p.x);
                while (angle < 0) angle += TWO_PI;
                while (angle >= TWO_PI) angle -= TWO_PI;
//                cout << angle << " " << endl;
                sweep_points.pb({sqrt((cities[j].y - top_p.y) * (cities[j].y - top_p.y) + (cities[j].x - top_p.x) * (cities[j].x - top_p.x)), angle, 0, j});
            }
            for (int j = 0; j < p; ++j) {
                double angle = atan2(peaks[j].y - top_p.y, peaks[j].x - top_p.x);
                double peak_dist = sqrt((top_p.y - peaks[j].y) * (top_p.y - peaks[j].y) + (top_p.x -peaks[j].x) * (top_p.x -peaks[j].x));
                double d_angle = asin(1.0 * peaks[j].r / peak_dist);
                double dist = sqrt(peak_dist * peak_dist - peaks[j].r * peaks[j].r);
                double l_angle = angle - d_angle;
                while (l_angle < 0) l_angle += TWO_PI;
                while (l_angle >= TWO_PI) l_angle -= TWO_PI;
                double r_angle = angle + d_angle;
                while (r_angle < 0) r_angle += TWO_PI;
                while (r_angle >= TWO_PI) r_angle -= TWO_PI;
//                cout << l_angle << " " << r_angle << endl;
                sweep_points.pb({dist, l_angle, 1, -(j + 1)});
                sweep_points.pb({dist, r_angle, -1, -(j + 1)});
            }
            sort(sweep_points.begin(), sweep_points.end());

        }
        n_components++;
    }
    cout << n_components - 1 << endl;
    
    return 0;
}