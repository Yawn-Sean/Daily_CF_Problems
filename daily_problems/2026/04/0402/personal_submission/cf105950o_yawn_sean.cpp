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

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> path(n);
	while (m --) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		path[u].emplace_back(v, w);
		path[v].emplace_back(u, w);
	}

	vector<int> dis(n, 2'000'000'000);
	dis[0] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dis[u] == d) {
			for (auto &[v, w]: path[u]) {
				if (max(w, d) < dis[v]) {
					dis[v] = max(w, d);
					pq.push({dis[v], v});
				}
			}
		}
	}

	int d;
	cin >> d;

	vector<int> v1(d), v2(d);
	for (auto &x: v1) cin >> x, x = dis[x - 1];
	for (auto &x: v2) cin >> x;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int ans = 0;
	for (int i = d - 1; i >= 0; i --) {
		if (v1[i] <= v2.back()) {
			v2.pop_back();
			ans ++;
		}
	}

	cout << ans;

	return 0;
}