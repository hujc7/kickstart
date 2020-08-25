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

void solve() {
    // n: number of junctions
    // m: streets
    // s: stone type
    // r: recipes
    int n, m, s, r;
    cin >> n >> m >> s >> r;
    
    // m lines: streets -> adjacent list
    vector<vi> stts(m);
    for (int i = 0; i < m; ++i) {
        int f, e;
        cin >> f >> e;
        stts[f].pb(e);
        stts[e].pb(f);
    }

    // n lines: stones at junctions
    vector<vi> stones(n);
    for (int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        stones[i].resize(tmp);
        for (auto &c: stones[i])
            cin >> c;
    }

    


    // walk along street with no stone cost no energy
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        solve();
    }

    return 0;
}