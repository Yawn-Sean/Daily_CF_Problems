#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> pl(n);
	for (int i = 0; i < n; i++) {
		cin >> pl[i];
	}
	
	vector<vector<pair<int,int> > > path(n);
	for (int i = 1; i < n; i++) {
		int u, v, cap;
		cin >> u >> v >> cap;
		--u; --v;
		path[u].push_back({v, cap});
		path[v].push_back({u, cap});
	}
	
	vector<pair<int,int>> from(n);
	function<void(int,int)> dfs = [&](int u, int fa) {
		for (auto& [v, c]: path[u]) {
			if (v != fa) {
				from[v] = {u, c};			
				dfs(v, u);
			}
		}
	};
	
	dfs(0, -1);
	
	vector<vector<int>> cnt(n, vector<int>(n + 1));
	vector<int> order(n);
	vector<int> ans(n);
	
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return pl[i] < pl[j];
	});
	
	for (auto&i: order) {
		int u = i, t = 0;
		while (u != 0) {
			auto [p, c] = from[u];
			while (cnt[u][t] == c) { t++; }
			cnt[u][t]++;
			u = p;
			t++;
		}
		ans[i] = t;
	}
	
	for (auto &x: ans) { cout << x << ' '; }
	return 0;
}
