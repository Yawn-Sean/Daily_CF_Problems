#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// https://codeforces.com/contest/835/submission/262893773

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();
    Manacher f(s);
    string_hash h(s);

    RangeAddTree<int> c(n);
    vector<vector<int>> p(n, vector<int>(n));
    for (int l = 1; l <= n; ++l) {
    	for (int i = 0; i + l <= n; ++i) {
    		int j = i + l - 1;
    		if (f.is_palin(i, j + 1)) {
    			p[i][j] = 1;
    		}
    		if (l > 1) {
    			int d = l / 2;
    			if (h.substring_hash(i, i + d) == h.substring_hash(j - d + 1, j + 1)) {
    				if (p[i][i + d - 1] > 0) {
    					p[i][j] = p[i][i + d - 1] + 1;
    				}
    			}
    		}
    		if (p[i][j] > 0) c.add(0, p[i][j] - 1, 1);
    	}
    }

    for (int i = 0; i < n; ++i) {
    	cout << c.get(i) << " \n"[i == n - 1];
    }

    return 0;
}
