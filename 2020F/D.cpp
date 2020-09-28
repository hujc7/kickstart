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
#define per(i,R,L) for (int i = R; i > L; --i)
#define EACH(x, a) for (auto& x: a)

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
    EACH(x, v)
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
	// write("\n");
    cout << endl;
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class T> void print(vector<T>& v) {
    EACH(x, v)
        write(x, " ");
    // write("\n");
    cout << endl;
}

map<vi, double> memo;

double dfs(int n, int m, int k, vi& state, vector<int>& target) {
    auto it = memo.find(state);
    if (it != memo.end()) return it->second;

    int good = 0;
    double res = 0;
    for (int i = 0, j; i < m; i = j+1) {
        for (j = i; j+1 < m && state[j] == state[j+1];) ++j;
        if (state[j] == target[j]) continue;
        state[j]++;
        good += j - i + 1;
        res += dfs(n, m, k, state, target) * (j-i+1);
        state[j]--;
    }
    res /= good;  // avergae of rerolls after this roll
    res += m * 1.0 / good;  // add expectation of current roll

    return memo[state] = res;
}

void solve() {
    // n: dies, m: sides, k: groups
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(m, 0);
    rep(i, m-k, m) cin >> v[i];

    vi state(m, 0);
    memo.clear();
    memo[v] = 0;
    double res = dfs(n, m, k, state, v);

    cout << setprecision(10) << res;
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