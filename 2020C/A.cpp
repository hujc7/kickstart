#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <utility>
using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define REP(i,L,R) for (int i = L; i < R; ++i)
#define PER(i,L,R) for (int i = R; i >= L; --i)
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
	write("\n");
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
    write("\n");
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    read(v);

    int res = 0, last = -1;
    for (int i = 0; i < n; ++i) {
        int val = v[i];
        if (val == k) {
            last = k;
        } else if (val == last-1) {
            last = val;
            if (val == 1) res++;
        } else {
            last = -1;
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        // read input

        // solve
        cout << "Case #" << cn << ": ";
        solve();
        cout << "\n";
    }

    return 0;
}