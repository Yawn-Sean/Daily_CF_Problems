#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<vector<pair<int, i64> >> path(n);
	for (int i = 0; i < n - 1; i++) {
		int u;
		i64 w;
		cin >> u >> w;
		--u;
		path[i + 1].push_back({u, w});
		path[u].push_back({i + 1, w});
	}
	
	vector<int> sz(n);
	
	function<int(int,int)> dfs1 = [&](int u, int fa) -> int {
		int res = 1;
		for (auto& pr: path[u]) {
			int v = pr.first;
			if (v != fa) {
				res += dfs1(v, u);			
			}
		}
		sz[u] = res;
		return res;
	};
	
	dfs1(0, -1);
	
	function<int(int,int,i64)> dfs2 = [&](int u, int fa, i64 mx) -> int {
		if (mx > a[u]) {
			// cout << u << ' ' << mx << '\n';
			return sz[u];
		}
		
		int res = 0;
		for (auto& pr: path[u]) {
			int v = pr.first;
			if (v == fa) continue;
			
			i64 w = pr.second;
			i64 new_mx = max(0ll, mx) + w;
			res += dfs2(v, u, new_mx);
		}
		return res;
	};
	
	int ans = dfs2(0, -1, 0ll);
	cout << ans << '\n';
    return 0;
}
