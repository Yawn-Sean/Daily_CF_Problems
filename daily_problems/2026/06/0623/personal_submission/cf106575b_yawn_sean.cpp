#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	long long c;
	cin >> n >> m >> k >> c;

	vector<int> blocked(n, 0);
	while (k --) {
		int x;
		cin >> x;
		x --;
		blocked[x] = 1;
	}

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	vector<vector<pair<int, int>>> path(n);

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;

		if (blocked[u] && blocked[v]) continue;
		
		int w = 0;
		if (blocked[u]) w = nums[u];
		if (blocked[v]) w = nums[v];

		path[u].emplace_back(v, w);
		path[v].emplace_back(u, w);
	}

	vector<long long> dis(n, 2 * c + 5);
	dis[0] = 0;

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
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

	cout << (dis[n - 1] <= 2 * c ? dis[n - 1] / 2 : -1);

	return 0;
}