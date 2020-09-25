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

const ll mod = 1e9;

pair<ll, ll> char2move(char c) {
    if (c == 'N') return mp(-1, 0);
    else if (c == 'S') return mp(1, 0);
    else if (c == 'E') return mp(0, 1);
    return mp(0, -1);
}

pair<ll, ll> parse(int& index, string& s) {
    ll x = 0, y = 0;
    while (index < s.size() && s[index] != ')') {
        char c = s[index];
        pair<ll, ll> mv;
        if (isalpha(c)) {
            mv = char2move(c);

            x = (x + mod + mv.fi) % mod;
            y = (y + mod + mv.se) % mod;
        } else {
            // is digit
            ll time = c - '0';
            index += 2;
            mv = parse(index, s);
            
            x = (x + time*mv.fi) % mod;
            y = (y + time*mv.se) % mod;
        }
        index++;
    }

    return mp(x, y);
}

void solve() {
    string s; cin >> s;

    int index = 0;
    auto mv = parse(index, s);

    cout << mv.se+1 << " " << mv.fi+1;
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