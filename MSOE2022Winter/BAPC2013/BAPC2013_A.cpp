//
// Created by Jonny Keane on 3/6/22.
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

struct Bill {
    long price = 0;
    bool is_consistent = true;
};

struct Car {
public:
    int catalog;
    int pickup;
    int per_km;
    Car(int c = 0, int p = 0, int pk = 0) : catalog(c), pickup(p), per_km(pk) {}
};

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, Car> cars;
    map<string, string> owners;
    for (int i = 0; i < n; ++i) {
        string name;
        int c, p, pk;
        cin >> name >> c >> p >> pk;
        cars[name] = Car(c, p, pk);
        owners[name] = "";
    }
    map<string, Bill> bills; // { Bill, is_consistent }
    map<string, string> curr_cars;
    for (int i = 0; i < m; ++i) {
        int t;
        string e, driver;
        cin >> t >> driver >> e;
        if (bills.find(driver) == bills.end()) {
            bills[driver] = Bill();
            curr_cars[driver] = "";
        }
        if (e == "p") {
            string c;
            cin >> c;
            string curr_owner = owners[c];
//            if (!curr_owner.empty()) { // if someone owns the car, there was an omitted return for them
//                bills[curr_owner].is_consistent = false;
//            }
            if (!curr_cars[driver].empty()) { // if the event spy has a car, there was an omitted return for them
                bills[driver].is_consistent = false;
            }
            bills[driver].price += cars[c].pickup;
            curr_cars[driver] = c;
            owners[c] = driver;
        } else if (e == "r") {
            int km;
            cin >> km;
            if (curr_cars[driver].empty()) { // if you don't have a car, you omitted a pick up
                bills[driver].is_consistent = false;
            }
            string curr_car = curr_cars[driver];
            owners[curr_car] = "";
            curr_cars[driver] = "";
            bills[driver].price += km * cars[curr_car].per_km;
//            cars[curr_car].curr_km = km;
        } else if (e == "a") {
            long percent;
            cin >> percent;
            if (curr_cars[driver].empty()) { // if you don't have a car, you can't get in an accident
                bills[driver].is_consistent = false;
            }
            string curr_car = curr_cars[driver];
            bills[driver].price += (percent * cars[curr_car].catalog) / 100l;
            if ((percent * cars[curr_car].catalog) % 100l != 0) {
                ++bills[driver].price;
            }
        }
    }
    for (auto p: curr_cars) {
        if (p.second != "") { // if you haven't returned a car, you need to
            bills[p.first].is_consistent = false;
        }
    }
    for (auto bill: bills) {
        cout << bill.first << " ";
        if (bill.second.is_consistent) {
            cout << bill.second.price << endl;
        } else {
            cout << "INCONSISTENT" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        solve();
    }
    return 0;
}
