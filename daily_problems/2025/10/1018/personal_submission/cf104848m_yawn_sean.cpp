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

	int n, m, T;
	cin >> n >> m >> T;

	vector<vector<pair<int, long double>>> path(n);

	while (m --) {
		int u, v, l, c;
		cin >> u >> v >> l >> c;
		u --, v --;

		long double w = sqrtl(1ll * l * c);
		path[u].emplace_back(v, w);
		path[v].emplace_back(u, w);
	}

	long double inf = 1e18;
	vector<long double> dis(n, inf);
	dis[0] = 0;

	priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;
	pq.push({dis[0], 0});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();

		if (dis[u] == d) {
			for (auto &[v, w]: path[u]) {
				long double nd = d + w;
				if (nd < dis[v]) {
					dis[v] = nd;
					pq.push({nd, v});
				}
			}
		}
	}

	cout << fixed << setprecision(15) << dis[n - 1] * dis[n - 1] / T;

	return 0;
}