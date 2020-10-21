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

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    read(v);

    vector<vector<double>> dp(n, vector<double>(n));
    vector<double> row(n), col(n);
    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i-1] + v[i-1];

    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i + k <= n; ++i) {
            int j = i + k -1;
            dp[i][j] += prefix[j+1] - prefix[i] + 1.0 * (row[i] + col[j]) / (k-1);
            row[i] += dp[i][j];
            col[j] += dp[i][j];
        }
    }

    // cout << endl;
    // for (auto &r: dp) {
    //     for (auto c: r) cout << c << " ";
    //     cout << endl;
    // }

    cout << setprecision(10) << dp[0][n-1];
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