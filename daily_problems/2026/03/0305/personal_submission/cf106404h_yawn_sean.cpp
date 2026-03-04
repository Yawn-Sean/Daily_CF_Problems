#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	int inf = 11e8;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		vector<vector<pair<int, int>>> path(n);
		while (m --) {
			int u, v, w;
			cin >> u >> v >> w;
			u --, v --;
			path[u].emplace_back(v, w);
			path[v].emplace_back(u, w);
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		for (int i = 0; i < n; i ++) pq.push({nums[i], i});

		while (!pq.empty()) {
			auto [d, u] = pq.top(); pq.pop();
			if (nums[u] == d) {
				for (auto &[v, w]: path[u]) {
					if (nums[u] + w < nums[v]) {
						nums[v] = nums[u] + w;
						pq.push({nums[v], v});
					}
				}
			}
		}

		vector<int> dis(n, inf);
		dis[0] = 0;

		pq.push({0, 0});

		while (!pq.empty()) {
			auto [d, u] = pq.top(); pq.pop();
			if (dis[u] == d) {
				for (auto &[v, w]: path[u]) {
					if (dis[u] + w < dis[v] && dis[u] + w <= nums[v]) {
						dis[v] = dis[u] + w;
						pq.push({dis[v], v});
					}
				}
			}
		}

		cout << (dis[n - 1] < inf ? "YES\n" : "NO\n");
	}

	return 0;
}