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

void dfs(int cur, int interval, vector<int>& path, vector<int>& res, vector<vector<int>>& graph) {

    path.pb(cur);
    EACH(child, graph[cur]) 
        dfs(child, interval, path, res, graph);
    path.pop_back();

    res[cur]++;
    int m = path.size();
    if (m >= interval) {
        res[path[m - interval]] += res[cur];
    }
        
}

double solve(int n, int a, int b, vector<int>& v) {
    EACH(c, v) c--;
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < n-1; ++i)
        graph[v[i]].pb(i+1);

    vector<int> va(n), vb(n);
    
    vector<int> path;
    dfs(0, a, path, va, graph);
    dfs(0, b, path, vb, graph);
    
    double res = 0;
    for (int i = 0; i < n; ++i) {
        double pa = va[i], pb = vb[i];
        pa /= n;
        pb /= n;
        res += pa + pb - pa*pb;
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

        // solve
        double res = solve(n, a, b, v);
        cout << "Case #" << cn << ": ";
        cout << fixed << setprecision(9);
        cout << res;
        cout << "\n";
    }

    return 0;
}