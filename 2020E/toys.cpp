#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
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

ll check(vi& E, vi& R, ll used) {
    int m = E.size();
    vector<ll> until_time(m);
    ll time = 0;

    for (int i = 0; i < 2*m; ++i) {
        int index = i % m;
        if (((used >> index) & 1) == 0) continue;
        // cout << index << " " << int(((used >> index) & 1) == 1) << "\n";
        if (time >= until_time[index]) {
            time += E[index];
            until_time[index] = time + R[index];
        } else {
            return time;
        }
    }

    return LLONG_MAX;
}

int countBits(ll n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

pair<int, ll> toys(vi& E, vi& R) {
    // E: enjoy time, time to play the toy
    // R: remember time, cool down time
    int time = 0;

    int m = E.size();

    ll res = 0;
    int count = INT_MAX;
    for (int i = 1; i < (1 << m); ++i) {
        ll tmp = check(E, R, i);
        // cout << bitset<12>(i) << ": " << tmp << "\n";
        int bits = m - countBits(i);
        if (tmp > res) {
            res = tmp;
            count = bits;
        } else if (tmp == res) {
            count = min(count, bits);
        }
    }   
    
    return mp(count, res);
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