#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
using namespace std;
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define fi first
#define se second
#define REP(i,L,R) for (int i = L; i <  R; ++i)
#define PER(i,L,R) for (int i = R; i >= L; --i)

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using ii = pair<int, int>;

void readn(vector<int>& v) {
    for (auto &c: v) cin >> c;
}

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

void solve(vector<int>& v) {
    int m = v.size();
    int run_max = -1;

    int res = 0;
    for (int i = 0; i < m; ++i) {
        int c = v[i];
        if (c > run_max && (i == m-1 || c > v[i+1]))
            res++;
        run_max = max(run_max, c);
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        int n; cin >> n;
        vector<int> v(n);
        readn(v);

        cout << "Case #" << cn << ": ";
        solve(v);
        cout << "\n";
    }

    return 0;
}