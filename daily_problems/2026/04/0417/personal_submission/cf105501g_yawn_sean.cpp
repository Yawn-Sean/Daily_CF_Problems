#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> graph(n);
	for (auto &x: graph) {
		cin >> x;
		x --;
	}

	vector<vector<int>> rev_graph(n);
	for (int i = 0; i < n; i ++)
		rev_graph[graph[i]].emplace_back(i);

	vector<int> indeg(n, 0);
	for (int x : graph)
		indeg[x] ++;

	vector<int> stk;
	for (int i = 0; i < n; i ++)
		if (indeg[i] == 0) stk.emplace_back(i);

	while (!stk.empty()) {
		int u = stk.back(); stk.pop_back();
		indeg[graph[u]] --;
		if (indeg[graph[u]] == 0)
			stk.emplace_back(graph[u]);
	}

	vector<int> vis(n, 0);
	int ans = 0;

	auto dfs = [&] (auto &self, int u) -> pair<int, int> {
		int v0 = 0, v1 = 1;
		for (auto &v: rev_graph[u]) {
			if (!vis[v]) {
				auto [x0, x1] = self(self, v);
				v0 += max(x0, x1);
				v1 += x0;
			}
		}
		return {v0, v1};
	};

	for (int i = 0; i < n; i ++) {
		if (indeg[i] && !vis[i]) {
			vector<int> cycle = {i};
			vis[i] = 1;
			while (graph[cycle.back()] != i) {
				cycle.emplace_back(graph[cycle.back()]);
				vis[cycle.back()] = 1;
			}

			vector<int> v0s, v1s;

			for (auto &u: cycle) {
				auto [v0, v1] = dfs(dfs, u);
				v0s.emplace_back(v0);
				v1s.emplace_back(v1);
			}

			int k = v0s.size();
			int res = 0;

			int val0 = 0, val1 = 0;
			for (int j = 1; j < k; j ++) {
				int nv0 = max(val0, val1) + v0s[j];
				int nv1 = val0 + v1s[j];
				val0 = nv0; val1 = nv1;
			}
			res = max(res, v0s[0] + max(val0, val1));

			val0 = 0; val1 = 0;
			for (int j = 0; j < k - 1; j ++) {
				int nv0 = max(val0, val1) + v0s[j];
				int nv1 = val0 + v1s[j];
				val0 = nv0; val1 = nv1;
			}
			res = max(res, v0s[k - 1] + max(val0, val1));

			ans += res;
		}
	}

	cout << n - ans;

	return 0;
}