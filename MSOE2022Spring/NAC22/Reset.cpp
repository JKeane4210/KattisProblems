//
// Created by keanej on 6/2/2022.
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

    int n, c;
    cin >> n >> c;
//    n = 20001, c = 15;
    int times[n][2];
    ll time_needed = 0;
    for (int i = 0; i < n; ++i) {
        cin >> times[i][0] >> times[i][1]; // time to complete task currently and research value
//        times[i][0] = 1000000000;
//        times[i][1] = 1;
        time_needed += times[i][0];
    }

    // special case: check 0
    ll curr_time_needed = time_needed;
    if (curr_time_needed <= c) {
        cout << 0 << endl;
        return 0;
    }
    priority_queue<int> pq0;
    for (int i = 0; i < n; ++i) {
        if (times[i][0] >= times[i][1]) {
            pq0.push(times[i][1]);
        } else if (times[i][0] > 0) {
            pq0.push(times[i][0]);
        }
    }
    // in order of value, try spending a second to research
    int time_before_reset = c;
    while (!pq0.empty() && time_before_reset != 0) {
        int top = pq0.top();
        pq0.pop();
        --time_before_reset;
        curr_time_needed -= top;
        if (curr_time_needed <= time_before_reset) {
            cout << 0 << endl;
            return 0;
        }
    }

    // binary search number of resets -> logn (maybe number of research days?)
    //      for each reset
    //          for each task -> research
    //              do you have enough to avoid crisis

    // observation: if I can find the number of research days that I have to do avoid reset, then I am good
    // hard case: n < c -> have to choose which things to execute each day
    //      observation: will always take the greatest until the day where there is just a portion left
    //          I can choose this to research for t / d resets

    ll left = 0, right = 2000000000000000;
    ll min_resets = right;
    while (left <= right) {
        ll research_resets = left + (right - left) / 2ll;
//        cerr << "Research Resets: " << research_resets << " (" << left << " " << right << ")" << endl;

        curr_time_needed = time_needed;
        priority_queue<tuple<int, int, int>> pq; // {value, number of resets}
        int remaining_time[n];
        fill(remaining_time, remaining_time + n, -1);
        for (int i = 0; i < n; ++i) {
            int researches = times[i][0] / times[i][1]; // full researches
            // if you cannot fit all full researches, put as many as you can into pq
            if (researches >= research_resets) {
                pq.push(make_tuple(times[i][1], research_resets, i));
//                cerr << i << ": " << research_resets << endl;
            }
            // if you can fit all full researches, put those in
            // and if you have space for one more
            else {
                pq.push(make_tuple(times[i][1], researches, i));
//                cerr << i << ": " << researches << endl;
                // if you have another day to remove the remainder, put in queue
                if (times[i][0] % times[i][1] != 0 && research_resets - researches >= 1) {
                    pq.push(make_tuple(times[i][0] % times[i][1], 1, i));
//                    cerr << i << ": " << 1 << endl;
                }
            }
        }
        // now pq should have all segments that could reasonably fit within this many research days (put in at most research_restarts number of items)
        // take the maximal value items until cannot fit any more
        // space is 1 second per research reset * c seconds per reset
        ll space = research_resets * c;
        while (!pq.empty() && space != 0) {
            auto top = pq.top();
            pq.pop();
//            cerr << "*" << get<0>(top) << " " << get<1>(top) << " " << get<2>(top) << endl;
//            cerr << space << endl;
            // if all the seconds from this section can be used
            if (get<1>(top) <= space) {
                remaining_time[get<2>(top)] = remaining_time[get<2>(top)] == -1 ?
                        times[get<2>(top)][0] - get<1>(top) * get<0>(top) :
                        remaining_time[get<2>(top)] - get<1>(top) * get<0>(top); // update how much time is remaining
                curr_time_needed -= get<0>(top) * get<1>(top); // remove the time
                space -= get<1>(top); // use up this space
            }
            // if only part of them can be taken
            else {
                curr_time_needed -= get<0>(top) * space;
                remaining_time[get<2>(top)] = remaining_time[get<2>(top)] == -1 ?
                        times[get<2>(top)][0] - (int)space * get<0>(top) :
                        remaining_time[get<2>(top)] - (int)space * get<0>(top);
                space = 0;
            }
        }
        // if after research_resets worth of researching, check if it fits with a fresh reset
        if (curr_time_needed <= c) {
            min_resets = min(min_resets, research_resets);
            right = research_resets - 1;
            continue;
        }
        // check if researching the most valuable additions during this reset could get us there
        priority_queue<int> pq2;
        for (int i = 0; i < n; ++i) {
//            cerr << (remaining_time[i] == -1 ? times[i][0] : remaining_time[i]) << endl;
            if (remaining_time[i] == -1) {
                if (times[i][0] >= times[i][1]) {
                    pq2.push(times[i][1]);
                } else if (times[i][0] > 0) {
                    pq2.push(times[i][0]);
                }
                continue;
            }
            if (remaining_time[i] >= times[i][1]) {
                pq2.push(times[i][1]);
            } else if (remaining_time[i] > 0) {
                pq2.push(remaining_time[i]);
            }
        }
        // in order of value, try spending a second to research
        bool solution_found = false;
        time_before_reset = c;
        while (!pq2.empty() && time_before_reset != 0) {
            int top = pq2.top();
            pq2.pop();
            --time_before_reset;
            curr_time_needed -= top;
            if (curr_time_needed <= time_before_reset) {
                min_resets = min(min_resets, research_resets);
                right = research_resets - 1;
                solution_found = true;
                break;
            }
        }
        if (!solution_found) {
            left = research_resets + 1;
        }
    }
    cout << min_resets << endl;

    return 0;
}