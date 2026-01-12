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

	int M = 70;
	vector<int> pr(M + 1), primes;
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			primes.emplace_back(i);
			for (int j = i; j <= M; j += i) {
				pr[j] = i;
			}
		}
	}

	vector<int> msks(M + 1, 0);
	for (int i = 0; i < 19; i ++)
		msks[primes[i]] = 1 << i;
	
	for (int i = 2; i <= M; i ++)
		if (pr[i] < i) msks[i] = msks[pr[i]] ^ msks[i / pr[i]];

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x, x = msks[x];

	vector<vector<int>> path(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> depth(n, 0), parent(n, -1);

	auto dfs = [&] (auto &self, int u, int p) -> void {
		parent[u] = p;
		for (auto &v: path[u]) {
			if (v != p) {
				nums[v] ^= nums[u];
				depth[v] = depth[u] + 1;
				self(self, v, u);
			}
		}
	};

	dfs(dfs, 0, -1);

	vector<vector<int>> nth_parent(20, vector<int>(n, -1));
	nth_parent[0] = parent;

	for (int i = 0; i < 19; i ++) {
		for (int j = 0; j < n; j ++) {
			if (nth_parent[i][j] >= 0) {
				nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
			}
		}
	}

	auto lca = [&] (int x, int y) -> int {
		if (depth[x] > depth[y]) swap(x, y);

		int d = depth[y] - depth[x];
		while (d) {
			y = nth_parent[__builtin_ctz(d)][y];
			d -= d & -d;
		}

		if (x == y) return x;

		for (int i = 19; i >= 0; i --) {
			if (nth_parent[i][x] != nth_parent[i][y]) {
				x = nth_parent[i][x];
				y = nth_parent[i][y];
			}
		}

		return parent[x];
	};

	int q;
	cin >> q;

	while (q --) {
		int u, v;
		cin >> u >> v;
		u --, v --;

		auto l = lca(u, v);
		int val = nums[u] ^ nums[v] ^ nums[l];
		if (l) val ^= nums[parent[l]];

		cout << (val ? 1 : 0) << '\n';
	}

	return 0;
}