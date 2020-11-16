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

// even position digit -> even
// odd position digit -> odd

ll dp[20][2];
ll dfs(int index, string& n, bool smaller) {
    // if (smaller) return pow(5, m-index);
    if (index == n.size()) return 1;
    ll &val = dp[index][smaller];
    if (val != -1) return val;

    int odd = (index % 2 == 0);
    int high = smaller ? 9: (n[index] - '0');

    ll res = 0;
    for (int i = odd; i <= high; i += 2) { 
        res += dfs(index+1, n, smaller || i < high);
    }

    return val = res;
}

ll boring_num(ll n) {
    string sn = to_string(n);

    memset(dp, -1, sizeof(dp));
    
    ll res = 0;
    for (int i = 0; i < sn.size(); ++i) {
        res += dfs(i, sn, i != 0);
    }

    return res;
}

void solve() {
    ll l, r; cin >> l >> r;

    cout << boring_num(r) - boring_num(l-1);
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