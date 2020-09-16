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

// Problem: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386edd

double solve(int n, int a, int b, vector<int>& v) {
    v.insert(v.begin(), -1);
    double w = 1.0/(n*n);
    // write(w, "\n");
    // print(v);

    double res = 0;
    REP(i, 0, n) {
        unordered_set<int> seen;
        int count = 0, ath = 0, imp = i;
        while (imp != -1) {
            if (ath == 0) {
                count++;
                seen.insert(imp);
                ath = a;
            }
            ath--;
            imp = v[imp];
        }
        REP(j, 0, n) {
            unordered_set<int> jseen(seen);
            int jcount = count, bth = 0, jmp = j;
            while (jmp != -1) {
                if (bth == 0) {
                    bth = b;
                    if (jseen.insert(jmp).second)
                        jcount++;
                }
                bth--;
                jmp = v[jmp];
            }
            res += w * jcount;
            // write(i, j, ": ");
            // EACH(c, seen)
            //     write(c, " ");
            // write("\n");
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        // read input
        int n, a, b; cin >> n >> a >> b;
        vector<int> v(n-1);
        read(v);
        EACH(c, v) c--;

        // solve
        
        auto res = solve(n, a, b, v);
        cout << "Case #" << cn << ": ";
        write(res);
        cout << "\n";
    }

    return 0;
}