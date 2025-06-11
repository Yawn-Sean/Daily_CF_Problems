#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, k;
		cin >> k;
		n = 2 * k;
		
		vector<vector<array<int, 2>>> path(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--; v--;
			
			path[u].push_back({v, w});
			path[v].push_back({u, w});
		}
		
		i64 mn = 0, mx = 0;
		function<int(int,int,int)> dfs = [&](int u, int p, int w) {
			int sz = 1;
			for (auto& v: path[u]) {
				if (v[0] != p) {
					sz += dfs(v[0], u, v[1]);
				}
			}
			// 最少经过这条边几次?
			mn += (sz % 2 == 1 ? w : 0);
			// 最多经过这条边几次?
			mx += 1ll * min(n - sz, sz) * w;
			return sz;
		};
		
		dfs(0, -1, 0);
		cout << mn << ' ' << mx << '\n';
	}
    return 0;
}
