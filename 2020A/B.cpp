#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define rep(i,L,R) for (int i = L; i < R; ++i)
#define rrep(i,L,R) for (int i = R; i > L; --i)
#define each(x, a) for (auto& x: a)

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class T> void read(T& x) {
    cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
    cin >> h;
    read(t...);
}
template<class T> void read(vector<T>& v) {
    each(x, v)
        read(x);
}
template<class A> void write(A x) {
	cout << x;
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class T> void print(vector<T>& v) {
    each(x, v)
        write(x, " ");
    write("\n");
}


// solve 1
// const int maxn = 50, maxk = 30;
// const int maxp = maxn * maxk;
// int dp[maxn+5][maxp+5];

// int dfs(int index, vvi& plates, int p) {
//     if (p == 0 || index == plates.size()) return 0;
//     int& val = dp[index][p];
//     if (val != -1) return val;

//     int res = 0, sum = 0;

//     // take no plates from current stack
//     res = max(res, dfs(index+1, plates, p));

//     // try taking plates
//     for (int i = 0; i < plates[index].size(); ++i) {
//         if (i > p - 1) break;
//         sum += plates[index][i];

//         res = max(res, sum + dfs(index+1, plates, p-i-1));
//     }

//     return val = res;
// }

// void solve() {
//     int n, k, p; cin >> n >> k >> p;
//     vector<vector<int>> plates(n, vector<int>(k));
//     each(v, plates) {
//         read(v);
//     }

//     memset(dp, -1, sizeof(dp));
//     int res = dfs(0, plates, p);

//     cout << res;
// }

// solve 2

void solve() {
    int n, k, p; cin >> n >> k >> p;
    vvi plates(n, vi(k));
    each(v, plates) {
        read(v);
        v.insert(v.begin(), 0);
    }

    // d[i][j]: max beauty for picking j plates from first i stacks
    // dp[i][j] = max(k = [0, p], dp[i-1][k] + )
    vvi dp(n+1, vi(p+1, 0));
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 0; j <= k; ++j) {
            sum += plates[i-1][j];
            for (int k = 0; k + j <= p; ++k)
                dp[i][k+j] = max(dp[i][k+j], sum + dp[i-1][k]);
        }
    }
    // cout << endl;
    // each(v, dp) print(v);


    cout << *max_element(dp[n].begin(), dp[n].end());
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        // solve
        cout << "Case #" << cn << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}