// #include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define pb push_back
#define ALL(c) (c).begin(), (c).end()

using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;


vector<int> highBuilding(int N, int A, int B, int C) {
    // N: total number of buildings, buildings have heights in [1, N]
    // A: number of building visible from the left
    // B: number of building visible from the right
    // C: common buildings, number of tallest buildings in the middle
    vector<int> res;
    if (A + B - C > N) return res;
    if (A == 1 && B == 1 && N != 1) return res;

    for (int i = 0; i < C; ++i) res.push_back(N);

    for (int i = 0; i < A-C; ++i) res.insert(res.begin(), N-i-1);

    for (int i = 0; i < B-C; ++i) res.pb(N-i-1);

    int i = 1;
    while (i < res.size()) {
        if (res[i-1] > 1 && res[i] > 1) break;
        i++;
    }
    
    for (int j = 0; j < N - (A + B - C); ++j) 
        res.insert(res.begin() + i, 1);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        int N, A, B, C;
        cin >> N >> A >> B >> C;
        auto v = highBuilding(N, A, B, C);

        cout << "Case #" << cn << ": ";
        if (v.empty()) cout << "IMPOSSIBLE";
        else for (auto c: v) cout << c << " ";
        cout << "\n";
    }

    return 0;
}