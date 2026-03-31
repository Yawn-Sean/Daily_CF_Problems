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

	vector<array<int, 3>> edges(m);
	for (auto &[u, v, w]: edges)
		cin >> u >> v >> w, u --, v --;

	long long inf = 1e15;
	vector<vector<long long>> dis(n + 1, vector<long long>(n, -inf));
	dis[0][0] = 0;

	for (int i = 0; i < n; i ++) {
		for (auto &[u, v, w]: edges) {
			if (dis[i][u] != -inf) {
				dis[i + 1][v] = max(dis[i + 1][v], dis[i][u] + w);
			}
		}
	}

	long double ans = 0;

	for (int u = 0; u < n; u ++) {
		if (dis[n][u] != -inf) {
			long double tmp = inf;
			for (int i = 0; i < n; i ++) {
				if (dis[i][u] != -inf) {
					tmp = min(tmp, (long double)(dis[n][u] - dis[i][u]) / (n - i));
				}
			}
			ans = max(ans, tmp);
		}
	}

	cout << fixed << setprecision(15) << ans;

	return 0;
}