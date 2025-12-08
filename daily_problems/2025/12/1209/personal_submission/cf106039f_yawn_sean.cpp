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

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> path(n + k);

	while (m --) {
		int u, v, c;
		cin >> u >> v >> c;
		u --, v --;
		path[u].emplace_back(v, c);
		path[v].emplace_back(u, c);
	}

	for (int u = 0; u < n; u ++) {
		int t;
		cin >> t;

		while (t --) {
			int v, c;
			cin >> v >> c;
			v = v - 1 + n;
			path[u].emplace_back(v, c);
			path[v].emplace_back(u, 0);
		}
	}

	long long inf = 1e16;
	vector<long long> dis(n + k, inf);

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	dis[0] = 0;
	pq.push({0, 0});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dis[u] == d) {
			for (auto &[v, w]: path[u]) {
				if (d + w < dis[v]) {
					dis[v] = d + w;
					pq.push({dis[v], v});
				}
			}
		}
	}

	cout << dis[n - 1];

	return 0;
}