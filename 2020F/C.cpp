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

vector<ii> getNeighbors(int a, int b, int S) {
    vector<ii> res;
    if (b % 2 == 0) {
        res.emplace_back(a-1, b-1);
        res.emplace_back(a, b-1);
        res.emplace_back(a, b+1);
    } else {
        res.emplace_back(a+1, b+1);
        res.emplace_back(a, b-1);
        res.emplace_back(a, b+1);
    }

    return res;
}

bool isValid(int a, int b, int S) {
    return 1 <= a && a <= S && 1 <= b && b <= 2*a - 1;
}

int dfs2(int a, int b, vector<vector<bool>>& state, int S, bool person) {
    int res = 0;
    vector<ii> nei = getNeighbors(a, b, S);

    for (auto &p: nei) {
        if (!isValid(p.fi, p.se, S) || state[p.fi][p.se]) continue;
        state[p.fi][p.se] = true;
        res = max(res, 1 + dfs2(p.fi, p.se, state, S, person));
        state[p.fi][p.se] = false;
    }

    return res;
}
// cur a, next b, flag if last person moved
int dfs(int ax, int ay, int bx, int by, vector<vector<bool>>& state, int S, bool person) {
    // cout << ax << " " << ay << " " << bx << " " << by << " "
    //      << (person ? "Alma" : "Berthe") << endl;

    int res = INT_MIN;
    vector<ii> nei = getNeighbors(ax, ay, S);

    int count = 0;
    for (auto &p: nei) {
        if (!isValid(p.fi, p.se, S) || state[p.fi][p.se]) continue;
        count++;
        state[p.fi][p.se] = true;
        res = max(res, 1 - dfs(bx, by, p.fi, p.se, state, S, !person));
        state[p.fi][p.se] = false;
    }

    if (count == 0) {
        res = INT_MAX;
        res = min(res, -dfs2(bx, by, state, S, !person));
    }

    // cout << ax << " " << ay << " " << bx << " " << by << " "
    //     << (person ? "Alma" : "Berthe") << " " << res << endl;
    // for (auto& r: state) {
    //     for (auto c: r) 
    //         cout << (int)c << " ";
    //     cout << endl;
    // }
    // cout << endl;
    

    return res;
}


void solve() {
    // cout << endl;
    int S, ax, ay, bx, by, C;
    cin >> S >> ax >> ay >> bx >> by >> C;
    vector<ii> ct(C);
    for (auto &p: ct) cin >> p.fi >> p.se;

    vector<vector<bool>> state(S+1, vector<bool>(2*S));
    for (auto &p: ct) {
        state[p.fi][p.se] = true;
    }
    state[ax][ay] = state[bx][by] = true;

    // odd col connects to even col in next row
    // (2,1) -> (3,2) 
    int res = dfs(ax, ay, bx, by, state, S, true);

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