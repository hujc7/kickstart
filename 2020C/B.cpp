#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define newl '\n'
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


// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003379bb#problem
// need to take care of 2 cases
// 1. only one letter
// 2. only one level


void solve() {
    int m, n; cin >> m >> n;
    vector<string> v(m);
    read(v);

    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char top = v[i][j];
            char bot = i + 1 == m ? 'a' : v[i+1][j];
            
            graph[bot];
            indegree[bot];

            if (top != bot) {
                if (graph[bot].insert(top).second) {
                    indegree[top]++;
                }
            }
        }
    }

    int count = indegree.size();
    queue<char> q;
    for (auto &p: indegree) {
        if (p.second == 0)
            q.push(p.first);
    }

    string res;
    while (!q.empty()) {
        char cur = q.front();
        count--;
        res.push_back(cur);
        q.pop();

        for (auto c: graph[cur]) {
            if (--indegree[c] == 0) {
                q.push(c);
            }
        }
    }

    if (count == 0) cout << res.substr(1);
    else cout << -1;
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