#include <bits/stdc++.h>

using namespace std;

int longestArthmetic(vector<int>& v) {
    int m = v.size();
    
    int res = 2, diff = v[1] - v[0], count = 2;
    for (int i = 2; i < m; ++i) {
        if (v[i] - v[i-1] != diff) {
            diff = v[i] - v[i-1];
            count = 2;
        } else {
            res = max(res, ++count);
        }
    }
    
    return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    for (auto cn = 1; cn <= t; ++cn) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& c: v) cin >> c;
        
        cout << "Case #" << cn << ": " << longestArthmetic(v) << endl;
    }
    
    return 0;
}
