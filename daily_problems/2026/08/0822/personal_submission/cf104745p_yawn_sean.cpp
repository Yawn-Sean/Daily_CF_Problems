#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	long long inf = 1e18;

	while (t --) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<vector<int>> path(n);
		vector<int> indeg(n, 0);

		while (m --) {
			int u, v;
			cin >> u >> v;
			u --, v --;

			path[u].emplace_back(v);
			indeg[v] ++;
		}

		vector<pair<int, int>> skis(k);

		for (auto &[u, v]: skis) {
			cin >> u >> v;
			u --, v --;
		}

		int target, start;
		cin >> target >> start;
		start --;

		vector<int> stk, topo;
		for (int i = 0; i < n; i ++) {
			if (indeg[i] == 0) {
				stk.emplace_back(i);
			}
		}

		while (!stk.empty()) {
			int u = stk.back(); stk.pop_back();
			topo.emplace_back(u);

			for (auto &v: path[u]) {
				indeg[v] --;
				if (!indeg[v]) stk.emplace_back(v);
			}
		}

		vector<long long> from_start(n, -inf);
		from_start[start] = 0;

		for (auto &i: topo) {
			for (auto &j: path[i]) {
				from_start[j] = max(from_start[j], from_start[i] + 1);
			}
		}

		if (*max_element(from_start.begin(), from_start.end()) >= target) {
			cout << 0 << '\n';
			continue;
		}

		vector<int> to_end(n, 0);

		reverse(topo.begin(), topo.end());

		for (auto &i: topo) {
			for (auto &j: path[i]) {
				to_end[i] = max(to_end[i], to_end[j] + 1);
			}
		}

		reverse(topo.begin(), topo.end());

		vector<long long> v0, v1;
		bool flg = false;

		for (auto &[s, e]: skis) {
			if (from_start[s] + to_end[e] + 1 >= target) flg = true;
			v0.emplace_back(from_start[s] + 1);
			v1.emplace_back(to_end[e]);
		}

		if (flg) cout << 1 << '\n';
		else {
			vector<long long> tmp(n, -inf);
			vector<vector<long long>> transition(k, vector<long long>(k, -inf));

			for (int i = 0; i < k; i ++) {
				auto [s, e] = skis[i];
				tmp[e] = 0;

				for (auto &u: topo) {
					for (auto &v: path[u]) {
						tmp[v] = max(tmp[v], tmp[u] + 1);
					}
				}

				for (int j = 0; j < k; j ++)
					transition[i][j] = tmp[skis[j].first] + 1;

				for (int u = 0; u < n; u ++) tmp[u] = -inf;
			}

			auto f = [&] (int i, int j) -> int {return i * k + j;};

			vector<vector<long long>> nth_transition(30, vector<long long>(k * k, -inf));

			for (int i = 0; i < k; i ++) {
				for (int j = 0; j < k; j ++) {
					nth_transition[0][f(i, j)] = transition[i][j];
				}
			}

			for (int i = 0; i < 29; i ++) {
				for (int u = 0; u < k; u ++) {
					for (int v = 0; v < k; v ++) {
						for (int w = 0; w < k; w ++) {
							nth_transition[i + 1][f(u, w)] = max(nth_transition[i + 1][f(u, w)], nth_transition[i][f(u, v)] + nth_transition[i][f(v, w)]);
						}
					}
				}
			}

			int ans = 2;

			for (int i = 29; i >= 0; i --) {
				bool flg = true;

				for (int u = 0; u < k; u ++) {
					for (int v = 0; v < k; v ++) {
						if (v0[u] + nth_transition[i][f(u, v)] + v1[v] >= target) {
							flg = false;
						}
					}
				}

				if (flg) {
					ans += 1 << i;
					vector<long long> nv0(k, -inf);

					for (int u = 0; u < k; u ++) {
						for (int v = 0; v < k; v ++) {
							nv0[v] = max(nv0[v], v0[u] + nth_transition[i][f(u, v)]);
						}
					}
					
					v0.swap(nv0);
				}
			}

			cout << ans << '\n';
		}
	}

	return 0;
}