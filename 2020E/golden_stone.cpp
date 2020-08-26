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

const ll INF = 1e12;

void solve() {
    // n: number of junctions
    // m: streets
    // s: stone type
    // r: recipes
    int N, M, S, R;
    cin >> N >> M >> S >> R;
    // cout << N << " " << M << " " << S << " " << R << "\n";
    // m lines: streets -> adjacent list
    vector<vi> stts = vector<vi>(N+1);;
    for (int i = 0; i < M; ++i) {
        int f, e;
        cin >> f >> e;
        stts[f].pb(e);
        stts[e].pb(f);
    }

    // for (int i = 1; i <= N; ++i) {
    //     cout << i << ": ";
    //     for (auto c: stts[i]) cout << c << " ";
    //     cout << "\n";
    // }

    priority_queue<vector<ll>> pq;

    // dp[s][n]: minimum cost to get stone s at junction n
    vector<vector<ll>> dp = vector<vector<ll>>(S+1, vector<ll>(N+1, INF));
    for (int i = 1; i <= N; ++i) {
        int num_stones; cin >> num_stones;
        for (int j = 0; j < num_stones; ++j) {
            int c; cin >> c;
            // get stone c at junction i cost 0 since already available
            dp[c][i] = 0;

            // -cost, node, stone
            pq.push({0, i, c});
        }
    }

    // r lines: recipies <product, <ingredient, count>>
    unordered_map<int, unordered_map<int, ll>>  recipies;
    for (int i = 0; i < R; ++i) {
        int k; cin >> k;
        unordered_map<int, ll> ingre;
        for (int j = 0; j < k; ++j) {
            int t; cin >> t;
            ingre[t]++;
        }
        int result_stone; cin >> result_stone;
        recipies[result_stone] = move(ingre);
    }

    // walk along street with no stone cost no energy
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        // negative cost
        ll cost = -v[0], node = v[1], stone = v[2];
        // cout << "Node: " << node << " Stone: " << stone << " cost: " << cost << "\n";
        if (cost > dp[stone][node]) continue;

        for (auto neighbor: stts[node]) {
            // can already get stone at neighbor with lower cost
            if (cost + 1 < dp[stone][neighbor]) {
                // update cost
                dp[stone][neighbor] = cost + 1;
                pq.push({-dp[stone][neighbor], neighbor, stone});
            }
        }

        for (auto &recipy: recipies) {
            // if recipy contains the stone, try alchimist
            if (recipy.se.count(stone)) {
                ll total_cost = 0;
                for (auto &need: recipy.se) {
                    total_cost += need.se * dp[need.fi][node];
                }
                if (total_cost < dp[recipy.fi][node]) {
                    dp[recipy.fi][node] = total_cost;
                    pq.push({-total_cost, node, recipy.fi});
                }
            }
        }
    }

    // for (auto& r: dp) {
    //     for (auto c: r) cout << c << " ";
    //     cout << "\n";
    // }
    ll res = INF;
    for (auto c: dp[1])
        res = min(res, c);
    if (res >= INF) cout << -1;
    else cout << res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        cout << "Case #" << cn << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}