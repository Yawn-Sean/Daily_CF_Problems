#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> nums(n), vis(1 << 20);
	for (auto &v: nums) cin >> v;

	vector<vector<int>> path(n);
	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		if (nums[u] == nums[v]) {
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}
		else vis[nums[u] ^ nums[v]] = 1;
	}

	vector<int> col(n, -1);

	auto dfs = [&] (auto &self, int u) -> void {
		for (auto &v: path[u]) {
			if (col[v] == -1) col[v] = col[u] ^ 1, self(self, v);
			else if (col[v] == col[u]) cout << -1, exit(0);
		}
	};

	for (int i = 0; i < n; i ++) {
		if (col[i] == -1) {
			col[i] = 0;
			dfs(dfs, i);
		}
	}

	int total = 0;
	for (int i = 0; i < n; i ++) total += col[i];

	int val = 1;
	while (vis[val]) val ++;

	cout << total << ' ' << val << '\n';
	for (int i = 0; i < n; i ++)
		if (col[i]) cout << i + 1 << ' ';

	return 0;
}