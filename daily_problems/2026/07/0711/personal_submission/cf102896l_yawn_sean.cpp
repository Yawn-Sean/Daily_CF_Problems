#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> parent(n, -1), vs(n);

	for (int i = 0; i < n; i ++) {
		int l, r, v;
		cin >> l >> r >> v;

		if (l) parent[l - 1] = i;
		if (r) parent[r - 1] = i;

		vs[i] = v;
	}

	vector<int> depth(n, 0);

	for (int i = 1; i < n; i ++) depth[i] = depth[parent[i]] + 1;

	vector<int> st_range(n), sorted_vs = vs;
	iota(st_range.begin(), st_range.end(), 0);
	sort(st_range.begin(), st_range.end(), [&] (int i, int j) {
		return vs[i] < vs[j];
	});
	sort(sorted_vs.begin(), sorted_vs.end());

	vector<vector<int>> nth_parent(20, vector<int>(n, -1));

	nth_parent[0] = parent;

	for (int i = 0; i < 19; i ++) {
		for (int j = 0; j < n; j ++) {
			if (nth_parent[i][j] != -1) {
				nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
			}
		}
	}

	auto lca = [&] (int u, int v) -> int {
		if (depth[u] > depth[v]) swap(u, v);

		int d = depth[v] - depth[u];

		while (d) {
			v = nth_parent[__builtin_ctz(d)][v];
			d -= d & -d;
		}

		if (u == v) return u;

		for (int i = 19; i >= 0; i --) {
			if (nth_parent[i][u] != nth_parent[i][v]) {
				u = nth_parent[i][u];
				v = nth_parent[i][v];
			}
		}

		return parent[u];
	};

	int q;
	cin >> q;

	while (q --) {
		int l, r;
		cin >> l >> r;

		if (l > sorted_vs.back()) cout << 1 << '\n';
		else if (r < sorted_vs[0]) cout << 1 << '\n';
		else {
			int pl = lower_bound(sorted_vs.begin(), sorted_vs.end(), l) - sorted_vs.begin();
			int pr = upper_bound(sorted_vs.begin(), sorted_vs.end(), r) - sorted_vs.begin();

			int vl = pl == 0 ? 0 : lca(st_range[pl], st_range[pl - 1]);
			int vr = pr == n ? 0 : lca(st_range[pr], st_range[pr - 1]);

			int p = lca(vl, vr);

			if (pl == 0 && pr == n) cout << 1 << '\n';
			else cout << 2 * (depth[vl] + depth[vr] - depth[p]) + 3 << '\n';
		}
	}

	return 0;
}