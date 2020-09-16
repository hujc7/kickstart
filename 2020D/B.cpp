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

void solve(vector<int>& v) {
    int res = 0;
    
    int icount = 1, dcount = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > v[i-1]) {
            icount++;
        } else if (v[i] < v[i-1]) {
            res += (icount -1) / 4;
            icount = 1;
        }

        if (v[i] < v[i-1]) {
            dcount++;
        } else if (v[i] > v[i-1]) {
            res += (dcount-1) / 4;
            dcount = 1;
        }

        // cout << icount << " " << dcount << endl;
    }
    res += (icount - 1)/4 + (dcount - 1)/4;

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        // read input
        int k; cin >> k;
        vector<int> v(k);
        readn(v);

        // solve
        cout << "Case #" << cn << ": ";
        solve(v);
        cout << "\n";
    }

    return 0;
}