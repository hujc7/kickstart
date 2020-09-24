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

// code
const int maxn = 2e5+1;
double lgf[maxn];
map<ii, double> memo;
int w, h, l, u, r, d;

double lgC(int n, int k) {
    return 0 <= k && k <= n ? lgf[n] - lgf[k] - lgf[n-k] : -1;
}

double getProb(int x, int y) {
    auto it = memo.find(mp(x, y));
    if (it != memo.end()) return it->second;
    if (0 <= x && x < w && 0 <= y && y < h)
        return exp(lgC(x + y, x) - lgf[2] * (x + y));

    double res = 0;
    if (x > 0)
        res += getProb(x-1, y) * (y == h ? 1.0 : 0.5);
    if (y > 0)
        res += getProb(x, y-1) * (x == w ? 1.0 : 0.5);
    return memo[mp(x, y)] = res;
}

void solve() {
    cin >> w >> h >> l >> u >> r >> d;
    w--, h--, l--, u--, r--, d--;

    // hole
    // 1 <= l <= x <= r <= w
    // 1 <= u <= y <= d <= h 

    // factorial
    lgf[0] = lgf[1] = 0;
    rep(i,2,w+h)
        lgf[i] = lgf[i-1] + log(i);
    memo.clear();
    memo[mp(0,0)] = 1;

    double ans = 1.0;
    // top left
    ans -= getProb(l, u);

    // top
    if (u) {
        rep(j, l+1, r+1)
            ans -= getProb(j, u-1) * (j == w ? 1.0 : 0.5);
    }

    // left
    if (l) {
        rep(i, u+1, d+1)
            ans -= getProb(l-1, i) * (i == h ? 1.0 : 0.5);
    }
    
    cout << setprecision(10) << ans;
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