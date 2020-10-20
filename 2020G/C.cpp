#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utimity>
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
    ll w, n; cin >> w >> n;
    vector<int> v(w);
    for (auto &c: v) {
        cin >> c;
        c--;
    }
    sort(v.begin(), v.end());
    // print(v);

    vector<ll> prefix(w+1);
    for (int i = 1; i <= w; ++i)
        prefix[i] = prefix[i-1] + v[i-1];
    // print(prefix);

    vector<ll> can;
    can.push_back(0);
    for (int i = 0; i < w; ++i) {
        can.push_back(v[i]);
        if (i+1 < w) {
            can.push_back((v[i] + v[i+1]) / 2);
            can.push_back((v[i] + v[i+1] + 1) / 2);
        }
    }
    can.push_back(((v.front() + v.back() + n) / 2) % n);
    can.push_back(((v.front() + v.back() + 1 + n) / 2) % n);
    can.push_back(n-1);

    ll res = 1e15;
    for (auto i: can) {
        ll sum = 0;
        auto mit = upper_bound(v.begin(), v.end(), i);
        auto lit = upper_bound(v.begin(), v.end(), i - n/2 - 1);
        auto rit = upper_bound(v.begin(), v.end(), i + n/2);

        // right
        if (mit < rit) {
            ll mid = mit - v.begin();
            ll right = rit - v.begin();
            right--;

            sum += (prefix[right+1] - prefix[mid]) - (right - mid + 1) * i;
        }
        // cout << sum << " ";
        // right right
        if (rit != v.end()) {
            ll right = rit - v.begin();
            sum += (w - right) * (n + i) - (prefix.back() - prefix[right]);
        }
        // cout << sum << " ";
        // left
        if (lit < mit) {
            ll left = lit - v.begin();
            ll mid = mit - v.begin();
            mid--;
            sum += i * (mid - left + 1) - (prefix[mid+1] - prefix[left]);
        }
        // cout << sum << " ";
        // left left
        if (lit != v.begin()) {
            ll left = lit - v.begin();
            left--;
            sum += prefix[left+1] + (n - i) * (left + 1);
        }
        // cout << sum << " -> ";
        // cout << i << ": " << sum << endl;
        res = min(res, sum);
    }

    cout << res;
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