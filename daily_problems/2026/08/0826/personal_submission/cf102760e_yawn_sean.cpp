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

	int n, m;
	cin >> n >> m;

	vector<int> tag(n);
	for (auto &x: tag) cin >> x;

	vector<vector<int>> path(n);

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> vis(n, -1), w0(n), w1(n);

	for (int i = 0; i < n; i ++) {
		if (vis[i] == -1) {
			vis[i] = 0;

			vector<int> que = {i};
			bool flg = true;

			for (int idx = 0; idx < que.size(); idx ++) {
				int u = que[idx];
				for (auto &v: path[u]) {
					if (vis[v] == -1) {
						vis[v] = vis[u] ^ 1;
						que.emplace_back(v);
					}
					else if (vis[u] == vis[v]) {
						flg = false;
					}
				}
			}

			if (flg) {
				int v0 = 1e9, v1 = 1e9;

				for (auto &u: que) {
					if (vis[u] == 0) v0 = min(v0, tag[u]);
					else v1 = min(v1, tag[u]);
				}

				for (auto &u: que) {
					if (vis[u] == 0) {
						w0[u] = v0;
						w1[u] = v1;
					}
					else {
						w0[u] = v1;
						w1[u] = v0;
					}
				}
			}
			else {
				int v = 1e9;
				for (auto &u: que) v = min(v, tag[u]);
				for (auto &u: que) w0[u] = v, w1[u] = v;
			}
		}
	}

	auto count_pairs = [&] (vector<int> &w) -> long long {
		long long ans = 0;
		vector<int> cnt(n + 1, 0);

		for (auto &x: w) {
			ans += cnt[x];
			cnt[x] ++;
		}

		return ans;
	};

	cout << max(count_pairs(w0), count_pairs(w1));

	return 0;
}