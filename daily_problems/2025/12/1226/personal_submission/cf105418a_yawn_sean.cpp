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

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> path(n);

	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		path[u].emplace_back(v, w);
	}

	long long inf = 1e15;

	vector<vector<long long>> dis(3, vector<long long>(n, inf));
	dis[0][0] = 0;

	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
	pq.push({0, 0, 0});

	while (!pq.empty()) {
		auto [d, u, cur] = pq.top(); pq.pop();

		if (dis[cur][u] == d) {
			if (cur == 0) {
				for (auto &[v, w]: path[u]) {
					if (dis[0][v] > d + w) {
						dis[0][v] = d + w;
						pq.push({dis[0][v], v, 0});
					}
					if (dis[1][v] > d + w / 2) {
						dis[1][v] = d + w / 2;
						pq.push({dis[1][v], v, 1});
					}
				}
			}
			else if (cur == 1) {
				for (auto &[v, w]: path[u]) {
					if (dis[2][v] > d + w / 2) {
						dis[2][v] = d + w / 2;
						pq.push({dis[2][v], v, 2});
					}
				}
			}
			else {
				for (auto &[v, w]: path[u]) {
					if (dis[2][v] > d + w) {
						dis[2][v] = d + w;
						pq.push({dis[2][v], v, 2});
					}
				}
			}
		}
	}

	cout << min(dis[1][n - 1], dis[2][n - 1]);

	return 0;
}