#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

#include "atcoder/dsu.hpp"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<array<int, 3>> edges(m);
	for (auto &[u, v, w]: edges) {
		cin >> u >> v >> w;
		u --, v --;
	}

	sort(edges.begin(), edges.end(), [&] (array<int, 3> &x, array<int, 3> &y) {
		return x[2] > y[2];
	});

	int l = 0, ans = 0;
	atcoder::dsu uf(n);
	vector<vector<int>> tmp_path(n);
	vector<int> cols(n, -1);

	auto solve = [&] (int l, int r) -> void {
		vector<int> tmp;

		for (int i = l; i < r; i ++) {
			auto [u, v, t] = edges[i];
			u = uf.leader(u), v = uf.leader(v);
			tmp.emplace_back(u), tmp.emplace_back(v);
			tmp_path[u].emplace_back(v), tmp_path[v].emplace_back(u);
		}

		for (auto &u: tmp) {
			if (cols[u] == -1) {
				int c0 = 0, c1 = 0;
				vector<int> stk = {u};

				cols[u] = 0;

				while (!stk.empty()) {
					auto u = stk.back();
					stk.pop_back();

					if (cols[u] == 0) c0 += uf.size(u);
					else c1 += uf.size(u);

					for (auto &v: tmp_path[u]) {
						if (cols[v] == -1) {
							cols[v] = cols[u] ^ 1;
							stk.emplace_back(v);
						}
						else if (cols[u] == cols[v]) {
							cout << "impossible\n";
							exit(0);
						}
					}
				}

				ans += min(c0, c1);
			}
		}

		for (int i = l; i < r; i ++) {
			auto [u, v, t] = edges[i];
			uf.merge(u, v);
		}

		for (auto &u: tmp) cols[u] = -1, tmp_path[u].clear();
	};

	for (int i = 0; i < m; i ++) {
		if (edges[i][2] != edges[l][2]) {
			solve(l, i);
			l = i;
		}
	}

	solve(l, m);

	cout << "possible\n";
	cout << ans << '\n';

	return 0;
}