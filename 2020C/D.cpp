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

int lowbit(int x) {
    return x & (-x);
}

class BIT {
public:
    int m;
    vector<ll> v;
    vector<ll> bit;
    BIT(int m) {
        this->m = m;
        v = vector<ll>(m);
        bit = vector<ll>(m+1);
    }

    void update(int index, ll u) {
        ll diff = u - v[index];
        v[index] = u;

        for (int i = index+1; i <= m; i += lowbit(i)) {
            bit[i] += diff;
        }
    }

    ll query(int index) {
        ll res = 0;
        for (int i = index+1; i > 0; i -= lowbit(i)) {
            res += bit[i];
        }

        return res;
    }

    int lowbit(int x) {
        return x & (-x);
    }
};

ll getSign(int i) {
    return i % 2 == 0 ? 1 : -1;
}

void solve() {
    int N, Q; cin >> N >> Q;
    vector<ll> v(N);
    read(v);

    BIT bit1(N), bit2(N);

    for (int i = 0; i < N; ++i) {    
        ll c = v[i];
        ll sign = getSign(i);
        bit1.update(i, sign * (i+1) * c);
        bit2.update(i, sign * c);
    }

    ll res = 0;
    while (Q--) {
        char c;
        ll l, r;
        cin >> c >> l >> r;
        l--;
        
        if (c == 'U') {
            ll sign = getSign(l);
            bit1.update(l, sign * (l+1) * r);
            bit2.update(l, sign * r);
        } else {
            r--;

            ll sign = getSign(l);
            ll sum1 = bit1.query(r) - bit1.query(l-1);
            ll sum2 = bit2.query(r) - bit2.query(l-1);
            ll tmp = sign * (sum1 - l*sum2);
            res += tmp;
        }
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