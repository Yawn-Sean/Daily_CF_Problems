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

	int n, m, q;
	cin >> n >> m >> q;

	vector<int> degs(n, n - 1);
	vector<vector<int>> path(n);

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;

		degs[u] --, degs[v] --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> vis(n, 0);

	int base = 0;
	vector<int> diff(n, 0);

	for (int i = 0; i < n; i ++) {
		if (degs[i] <= 1) {
			base ++;
			diff[i] --;
		}
	}

	map<pair<int, int>, int> pairs;

	for (int i = 0; i < n; i ++) {
		if (degs[i] >= 2 && degs[i] <= 3) {
			vis[i] = 1;
			for (auto &j: path[i]) vis[j] = 1;

			vector<int> tmp;
			for (int j = 0; j < n; j ++) {
				if (!vis[j]) {
					tmp.emplace_back(j);
				}
			}

			if (degs[i] == 2) {
				int u = tmp[0], v = tmp[1];

				diff[u] ++;
				diff[v] ++;
				pairs[{u, v}] --;

				if (i < u) pairs[{i, u}] --;
				else pairs[{u, i}] --;

				if (i < v) pairs[{i, v}] --;
				else pairs[{v, i}] --;
			}
			else {
				int u = tmp[0], v = tmp[1], w = tmp[2];
				pairs[{u, v}] ++;
				pairs[{u, w}] ++;
				pairs[{v, w}] ++;
			}

			vis[i] = 0;
			for (auto &j: path[i]) vis[j] = 0;
		}
	}

	while (q --) {
		int u, v;
		cin >> u >> v;
		u --, v --;

		if (u > v) swap(u, v);

		int ans = base + diff[u] + diff[v];
		if (pairs.find({u, v}) != pairs.end()) ans += pairs[{u, v}];

		cout << ans << '\n';
	}

	return 0;
}