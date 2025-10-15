#include <bits/stdc++.h>
using LL = long long;
using namespace std;

void solve() {

	int n;
	cin >> n;

	vector<int> deg(n);
	vector<vector<array<int,2>>> adj(n);
	for (int i = 1 ; i <= n - 1 ; ++i) {
		int u,v;
		cin >> u >> v;
		u -- , v --;
		adj[u].push_back({v , i});
		adj[v].push_back({u , i});
		++deg[u] , ++deg[v];
	}

	int mx = *max_element(deg.begin() , deg.end());
	cout << mx << "\n";
	vector<vector<int>> ans(mx);

	function<void(int,int,int)> dfs = [&] (int u,int par,int sta) {
		int pos = -1;
		for (auto [v , id] : adj[u]) {
			if (v == par) continue;
			++pos;
			if (pos == sta) ++pos;
			ans[pos].push_back(id);
			dfs(v , u , pos);
		}
	};
	dfs(0 , -1 , -1);

	for (int i = 0 ; i < mx ; ++i) {
		cout << (int)ans[i].size() << " ";
		for (auto x : ans[i]) cout << x << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
