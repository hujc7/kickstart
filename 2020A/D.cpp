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

struct TrieNode {
    int count;
    vector<TrieNode*> child;

    TrieNode() {
        this->count = 0;
        child = vector<TrieNode*>(26);
    }
};


class TrieTree {
public:
    TrieNode root;
    TrieTree() {
        root = TrieNode();
    }

    void add(string& word) {
        TrieNode* tmp = &root;
        for (auto c: word) {
            if (!tmp->child[c - sc]) {
                tmp->child[c - sc] = new TrieNode();
            }
            tmp = tmp->child[c - sc];
        }
        tmp->count++;
    }
    const char sc = 'A';
};

// pair<score, not_used>
ii dfs(TrieNode* node, int k, int depth) {
    if (!node) return mp(0, 0);

    int sum = 0;
    int count = node->count;

    for (auto tmp: node->child) {
        auto cur = dfs(tmp, k, depth+1);
        sum += cur.fi;
        count += cur.se;
    }

    int rounds = count / k;

    return mp(sum + rounds * depth, count % k);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<string> v(n);
    read(v);

    TrieTree tt;
    for (auto &w: v) {
        tt.add(w);
    }   

    cout << dfs(&tt.root, k, 0).fi;   
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