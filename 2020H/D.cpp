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
    int n, q; cin >> n >> q;
    vector<string> v(n);
    read(v);

    vector<int> qs(q), qt(q);
    for (int i = 0; i < q; ++i) {
        int t1, t2; cin >> t1 >> t2;
        // 1 indexed
        qs[i] = t1-1;
        qt[i] = t2-1;
    }
    
    vector<vector<int>> agd(26, vector<int>(26, INT_MAX));
    for (auto &s: v) {
        unordered_set<char> chars(s.begin(), s.end());
        vector<char> all_char(chars.begin(), chars.end());
        for (int i = 0; i < all_char.size(); ++i) {
            for (int j = i+1; j < all_char.size(); ++j) {
                int a = all_char[i] - 'A', b = all_char[j] - 'A';
                agd[a][b] = agd[b][a] = 1;
            }
        }
    }

    for (int i = 0; i < 26; ++i) agd[i][i] = 0;

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (agd[i][k] == INT_MAX || agd[k][j] == INT_MAX) continue;
                agd[i][j] = min(agd[i][j], agd[i][k] + agd[k][j]);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        string start = v[qs[i]];
        string end = v[qt[i]];
        
        int step = INT_MAX;
        for (auto ca: start) {
            int intca = ca - 'A';
            for (auto cb: end) {
                int intcb = cb - 'A';
                step = min(step, agd[intca][intcb]);
            }
        }

        cout << (step == INT_MAX ? -1 : step + 2) << " ";
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