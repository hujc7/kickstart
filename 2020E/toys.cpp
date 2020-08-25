#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
// #include <queue>
// #include <algorithm>
using namespace std;
#define pb push_back
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define fi first
#define se second

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using ii = pair<int, int>;

pair<int, ll> toys(vi& E, vi& R) {
    // E: enjoy time, time to play the toy
    // R: remember time, cool down time
    int time = 0;

    int m = E.size();
    
    ll sum_e = accumulate(ALL(E), 0ll);
    ll cur_time = sum_e;
    int count = 0;
    
    ll best_time = sum_e;
    int best_remove = 0;

    priority_queue<pair<ll, int>> pq;

    for (int i = 0; i < m; ++i) {
        int e = E[i], r = R[i];
        pq.emplace(e + r, i);
        cur_time += e;

        while (!pq.empty() && pq.top().fi > sum_e) {
            auto cur = pq.top();
            pq.pop();
            cur_time -= 2*E[cur.se];
            sum_e -= E[cur.se];
            count++;
        }

        if (cur_time > best_time) {
            best_time = cur_time;
            best_remove = count;
        } else if (cur_time == best_time) {
            best_remove = min(best_remove, count);
        }
    }

    if (!pq.empty()) return mp(m - pq.size(), LLONG_MAX);

    return mp(best_remove, best_time);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        int N; cin >> N;
        vi E(N), R(N);
        for (int i = 0; i < N; ++i) {
            cin >> E[i] >> R[i];
        }

        auto res = toys(E, R);

        cout << "Case #" << cn << ": ";
        cout << res.fi << " ";
        if (res.se == LLONG_MAX) cout << "INDEFINITELY";
        else cout << res.se;
        cout << "\n";
    }

    return 0;
}