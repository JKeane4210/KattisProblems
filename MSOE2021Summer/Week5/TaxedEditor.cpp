//
// Created by Jonny Keane on 6/24/21.
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

long long numberMissed(const vector<pair<int, int> >& books, long long speed) {
    priority_queue<long long> used;
    long long totalTime = 0;
    long long missed = 0;
    for (auto book: books) {
        used.push(book.second);
        totalTime += book.second;
        if (totalTime > book.first * speed) {
            totalTime -= used.top();
            used.pop();
            ++missed;
        }
    }
    return missed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > books(n);
    long long total = 0;
    long long left = 1;
    for (int i = 0; i < n; ++i) {
        int pages, days;
        cin >> pages >> days;
        books[i] = make_pair(days, pages);
        total += pages;
    }
    long long right = total;
    long long best = right;
    sort(books.begin(), books.end());
    long long mid = (left + right) / 2;
    while (left <= right) {
        if (numberMissed(books, mid) > m) {
            left = mid + 1;
        } else {
            best = min(mid, best);
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    cout << best << endl;

    return 0;
}