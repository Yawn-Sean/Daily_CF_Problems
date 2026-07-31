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

	int t;
	cin >> t;

	while (t --) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		a --, b --;

		vector<vector<int>> path(n);
		while (m --) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<int> dis(n, -1), vis(n, 0);
		vis[b] = 2, dis[b] = 0;

		queue<int> que; que.push(b);

		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (auto &v: path[u]) {
				vis[v] ++;
				if (vis[v] == 2) {
					dis[v] = dis[u] + 1;
					que.push(v);
				}
			}
		}

		cout << dis[a] << '\n';
	}

	return 0;
}