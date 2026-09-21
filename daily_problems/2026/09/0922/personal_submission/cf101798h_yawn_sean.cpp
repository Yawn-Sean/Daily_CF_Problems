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

	int n;
	cin >> n;

	vector<vector<int>> path(n);

	for (int i = 0; i < n / 2 * 3; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	bool flg;

	flg = true;

	for (auto &v: path) if (v.size() != 3) flg = false;

	if (!flg) cout << "NO\n";
	else {
		auto check = [&] (int x, int y) -> void {
			vector<int> que = {x, y};

			vector<int> dis(n, -1);
			dis[x] = 0, dis[y] = 0;

			vector<vector<int>> npath(n);

			for (int i = 0; i < que.size(); i ++) {
				int u = que[i];
				for (auto &v: path[u]) {
					if (dis[v] == -1) {
						dis[v] = dis[u] + 1;
						npath[u].emplace_back(v);
						npath[v].emplace_back(u);
						que.emplace_back(v);
					}
				}
			}

			for (int i = 0; i < n; i ++) {
				if (npath[i].size() > 2) {
					return ;
				}
			}

			vector<int> vis(n, 0);
			vector<vector<int>> chains;

			for (int i = 0; i < n; i ++) {
				if (!vis[i] && npath[i].size() == 1) {
					vector<int> chain = {i};
					vis[i] = 1;

					for (int j = 0; j < chain.size(); j ++) {
						int u = chain[j];
						for (auto &v: npath[u]) {
							if (!vis[v]) {
								vis[v] = 1;
								chain.emplace_back(v);
							}
						}
					}

					chains.emplace_back(chain);
				}
			}

			if (chains.size() != 2 || chains[0].size() != n / 2 || chains[1].size() != n / 2) return ;

			flg = false;
			for (auto &x: path[chains[0][0]]) if (chains[0].back() == x) flg = true;
			if (!flg) return ;

			flg = false;
			for (auto &x: path[chains[1][0]]) if (chains[1].back() == x) flg = true;
			if (!flg) return ;

			vector<int> idxs(n, -1);
			for (int i = 0; i < n / 2; i ++) idxs[chains[0][i]] = i;

			vector<int> tmp;
			for (int i = 0; i < n / 2; i ++) {
				int u = chains[1][i], chosen = -1;

				for (auto &v: path[u]) {
					if (idxs[v] != -1) {
						chosen = idxs[v];
					}
				}

				if (chosen == -1) return ;
				tmp.emplace_back(chosen);
			}

			int diff = (tmp[1] - tmp[0] + n) % (n / 2);

			if (diff != 1 && diff != n / 2 - 1) return ;

			for (int i = 1; i < n / 2; i ++) {
				if ((tmp[i] - tmp[i - 1] + n) % (n / 2) != diff) {
					return ;
				}
			}

			cout << "YES\n";
			for (auto &x: chains[1]) cout << x + 1 << ' '; cout << '\n';
			for (auto &x: tmp) cout << chains[0][x] + 1 << ' '; cout << '\n';
			exit(0);
		};

		for (auto &v: path[0]) check(0, v);

		cout << "NO\n";
	}

	return 0;
}