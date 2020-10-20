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

int lowbit(int x) {
    return x & (-x);
}

// bit + binary search
const int maxa = 1e5+5;
int n;
// vector<int> v;
// vector<int> bit;
int v[maxa];
int bit[maxa+1];

void update(int index, int diff) {
    v[index] += diff;

    for (int i = index+1; i <= n; i += lowbit(i)) {
        bit[i] += diff;
    }
}

int query(int index) {
    int sum = 0;

    for (int i = index+1; i > 0; i -= lowbit(i)) {
        sum += bit[i];
    }

    cout << "query, " << index << " : " <<sum << endl;
    return sum;
}

int bs(int index) {
    int left = 1, right = index;

    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (query(mid) >= mid) left = mid; 
        else right = mid-1;
    }

    return left;
}

void solve() {
    cin >> n;
    // vector<int> v(n);
    // read(v);
    memset(v, 0, sizeof(v));
    memset(bit, 0, sizeof(bit));

    rep(i, 0, n) {
        int tmp; cin >> tmp;
        update(tmp, 1);
        cout << bs(i+1) << " ";
    }
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