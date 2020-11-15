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

// one point can have multiple players
const ll offset = 1e5;
const ll INF = 1e9+7;
const ll NINF = -1e9-7;

ll check_x(ll mid, vector<ll>& x) {
    ll res = 0;
    for (int i = 0; i < x.size(); ++i) {
        res += llabs(mid + i - x[i]);
    }

    return res;
}

// binary search start point
ll BS_x(vector<ll>& x) {
    ll left = x.front() - offset, right = x.back() + offset;
    while (left < right) {
        ll l1 = left + (right - left) / 3;
        ll r1 = left + 2 * (right - left) / 3;
        ll tl1 = check_x(l1, x);
        ll tr1 = check_x(r1, x);
        if (tl1 > tr1) {
            left = l1 + 1;
        } else {
            right = r1;
        }
    }

    return check_x(left, x);
}

ll check_y(ll mid, vector<ll>& y) {
    ll res = 0;
    for (auto c: y) res += llabs(c - mid);

    return res;
}

ll BS_y(vector<ll>& y) {
    ll left = y.front(), right = y.back();
    while (left < right) {
        ll l1 = left + (right - left) / 3;
        ll r1 = left + 2 * (right - left) / 3;
        ll tl1 = check_y(l1, y);
        ll tr1 = check_y(r1, y);
        if (tl1 > tr1) {
            left = l1 + 1;
        } else {
            right = r1;
        }
    }

    return check_y(left, y);
}

void solve() {
    int n; cin >> n;
    // vector<vector<int>> v(n, vector<int>(2));
    vector<ll> px(n), py(n);
    for (int i = 0; i < n; ++i) cin >> px[i] >> py[i];
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    // cout << endl;
    ll rx = BS_x(px);
    ll ry = BS_y(py);
    // cout << rx << " " << ry << endl;
    cout << rx + ry;
    // cout << BS_x(px) + BS_y(py);
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