// #include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define pb push_back
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define fi first
#define se second
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;

ii toys(vi& E, vi& R) {
    int time = 0;
    
    return mp(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        int N; cin >> N;
        vi E(N), R(N);
        for (int i = 0; i < N; ++i) {
            cin >> E[i];
            cin >> R[i];
        }

        auto res = toys(E, R);

        cout << "Case #" << cn << ": ";
        cout << res.fi << " ";
        if (res.se == INT_MAX) cout << "INDEFINITELY";
        else cout << res.se;
        cout << "\n";
    }

    return 0;
}