#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
#include "atcoder/lazysegtree"

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

typedef pair<long long, int> node;

node op(node x, node y) {
	if (x.first < y.first) return x;
	if (x.first > y.first) return y;
	return {x.first, x.second + y.second};
}

node e() {return {(long long)1e18, 0};}

node mapping(long long x, node y) {return {y.first + x, y.second};}

long long composition(long long x, long long y) {return x + y;}

long long id() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<vector<int>> path(n);

	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> parent(n), ls(n), rs(n), depth(n, 0);
	int tmstamp = 0;

	auto dfs = [&] (auto &self, int u, int p) -> void {
		parent[u] = p;
		ls[u] = tmstamp ++;

		for (auto &v: path[u]) {
			if (v != p) {
				depth[v] = depth[u] + 1;
				self(self, v, u);
			}
		}

		rs[u] = tmstamp;
	};

	dfs(dfs, 0, -1);

	vector<vector<int>> nth_parent(20, vector<int>(n, -1));
	nth_parent[0] = parent;

	for (int i = 0; i < 19; i ++) {
		for (int j = 0; j < n; j ++) {
			if (nth_parent[i][j] != -1) {
				nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
			}
		}
	}

	vector<node> vec(n, {0, 1});
	atcoder::lazy_segtree<node, op, e, long long, mapping, composition, id> seg(vec);
	long long total_lazy = 0;

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

	auto kth_parent = [&] (int k, int u) -> int {
		for (int i = 0; i < 20; i ++) {
			if (k >> i & 1) {
				u = nth_parent[i][u];
			}
		}
		return u;
	};

	while (q --) {
		int u, v, x, y, z;
		cin >> u >> v >> x >> y >> z;
		u --, v --;
		x -= z, y -= z, total_lazy += z;

		if (u != v) {
			auto l = lca(u, v);
			int d = depth[u] + depth[v] - depth[l] * 2;

			for (int _ = 0; _ < 2; _ ++) {
				if (depth[u] - depth[l] > (d - 1) / 2) {
					int pos = kth_parent((d - 1) / 2, u);
					seg.apply(ls[pos], rs[pos], x);
				}
				else {
					int pos = kth_parent((d - 1) - (d - 1) / 2, v);
					total_lazy += x;
					seg.apply(ls[pos], rs[pos], -x);
				}
				swap(u, v);
				swap(x, y);
			}
		}

		auto [val, cnt] = seg.all_prod();
		cout << val + total_lazy << ' ' << cnt << '\n';
	}

	return 0;
}