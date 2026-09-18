#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
#include "atcoder/dsu.hpp"

using namespace std;

typedef pair<pair<int, int>, long long> edge;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<edge> edges(m);
	for (auto &[x, y]: edges) cin >> x.first >> x.second >> y;

	sort(edges.begin(), edges.end(), [&] (edge e1, edge e2) {return e1.second < e2.second;});

	atcoder::dsu uf(n + 1);
	vector<vector<int>> path(n + 1);

	long long ans = 0;

	for (auto &[ends, w]: edges) {
		auto [u, v] = ends;
		if (uf.merge(u, v)) {
			ans += w;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}
	}

	cout << 2 * ans << '\n';

	vector<int> order;

	auto dfs = [&] (auto &self, int u, int p) -> void {
		order.emplace_back(u);
		for (auto &v: path[u]) {
			if (v != p) {
				self(self, v, u);
				order.emplace_back(u);
			}
		}
	};

	dfs(dfs, 1, 0);

	cout << 2 * n - 1 << '\n';
	for (int i = 0; i < 2 * n - 1; i ++) cout << order[i] << " \n"[i == 2 * n - 2];

	return 0;
}