#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
// #define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define REP(i,L,R) for (int i = L; i < R; ++i)
#define PER(i,R,L) for (int i = R; i >= L; --i)
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
	cout << endl;
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
    cout << endl;
}

// problem: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386d5c#analysis
const int INF = 1e9, maxd = 17;
vvi ch;
vvi pa;
vi sz;

void dfs(int cur) {
    sz[cur] = 1;
    for (int i = 0; i < 2; ++i) {
        int child = ch[i][cur];
        if (child == -1) continue;
        dfs(child);
        sz[cur] += sz[child];
    }
}

void buildTree(int N, vi& D) {
    ch = vvi(2, vi(N+1, -1));
    pa = vvi(N+1, vi(maxd, -1));
    sz = vi(N+1, -1);

    stack<int> stk;
    // higher right door
    REP(i,0,N+1) {
        int last = -1;
        while (!stk.empty() && D[stk.top()] < D[i]) {
            // lr[1][stk.top()] = i;
            // pa[stk.top()][0] = i;
            last = stk.top();
            stk.pop();
        }
        if (last != -1) {
            ch[0][i] = last;
            pa[last][0] = i;
        }
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();
    // higher left door
    PER(i,N,0) {
        int last = -1;
        while (!stk.empty() && D[stk.top()] < D[i]) {
            // lr[0][stk.top()] = i;
            // pa[stk.top()][0] = i;
            last = stk.top();
            stk.pop();
        }
        if (last != -1) {
            ch[1][i] = last;
            pa[last][0] = i;
        }
        stk.push(i);
    }

    for (int i = 1; i < maxd; ++i) {
        for (int j = 0; j <= N; ++j) {
            pa[j][i] = pa[j][i-1] == -1 ? -1 : pa[pa[j][i-1]][i-1];
        }
    }
    dfs(0);
}

void solve(int N, int Q, vi& D, vi& SK) {
    buildTree(N, D);
    
    REP(i,0,Q) {
        int s = SK[2*i], k = SK[2*i+1];
        if (k == 1) {
            cout << s << " ";
            continue;
        }

        int u = D[s-1] < D[s] ? s-1 : s;
        if (sz[u] >= k-1) {
            if (D[s-1] < D[s]) {
                cout << s - (k - 1) << " ";
            } else {
                cout << s + (k - 1) << " ";
            }
            continue;
        }

        for (int i = maxd-1; i >= 0; --i) {
            int p = pa[u][i];
            if (p == -1) continue;
            if (sz[p] < k-1) u = p;
        }

        int p = pa[u][0], mvs = k - 1 - sz[u];
        if (ch[0][p] == u) {
            cout << p + mvs << " ";
        } else {
            cout << p +1 - mvs << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    for (int cn = 1; cn <= t; ++cn) {
        // read input
        int N, Q; read(N, Q);
        vi D(N+1);
        REP(i,1,N) read(D[i]);
        D[0] = INF + 1;
        D[N] = INF;

        vi SK(2*Q);
        EACH(c, SK) read(c);

        // solve
        cout << "Case #" << cn << ": ";
        solve(N, Q, D, SK);
        cout << "\n";
    }

    return 0;
}