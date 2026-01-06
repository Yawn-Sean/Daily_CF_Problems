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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<vector<pair<int, int>>> path(n);
		for (int i = 0; i < n - 1; i ++) {
			int u, v, w;
			cin >> u >> v >> w;
			u --, v --;
			path[u].emplace_back(v, w);
			path[v].emplace_back(u, w);
		}

		vector<long long> dp0(n, 0), dp1(n, 0);

		auto dfs1 = [&] (auto &self, int u, int p) -> void {
			long long v1 = 0, v2 = 0;
			for (auto &[v, w]: path[u]) {
				if (v != p) {
					self(self, v, u);
					long long nw = w + dp0[v];

					if (nw > v1) swap(v1, v2), v1 = nw;
					else if (nw > v2) v2 = nw;

					dp1[u] = max(dp1[u], dp1[v]);
				}
			}

			dp0[u] = v1;
			dp1[u] = max(dp1[u], v1 + v2);
		};

		dfs1(dfs1, 0, -1);

		long long ans = 0;

		auto dfs2 = [&] (auto &self, int u, int p, long long up0, long long up1) -> void {
			long long v1 = up0, v2 = 0, v3 = 0;
			long long w1 = 0, w2 = 0;

			ans = max(ans, min(dp1[u], up1));

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					long long nw = w + dp0[v];
					if (nw > v1) swap(v2, v3), swap(v1, v2), v1 = nw;
					else if (nw > v2) swap(v2, v3), v2 = nw;
					else if (nw > v3) v3 = nw;

					if (dp1[v] > w1) swap(w1, w2), w1 = dp1[v];
					else if (dp1[v] > w2) w2 = dp1[v];
				}
			}

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					long long nup0, nup1;
					long long nw = w + dp0[v];

					if (nw == v1) {
						nup0 = v2 + w;
						nup1 = v2 + v3;
					}
					else if (nw == v2) {
						nup0 = v1 + w;
						nup1 = v1 + v3;
					}
					else {
						nup0 = v1 + w;
						nup1 = v1 + v2;
					}

					if (dp1[v] == w1) nup1 = max(nup1, w2);
					else nup1 = max(nup1, w1);

					self(self, v, u, nup0, nup1);
				}
			}
		};

		dfs2(dfs2, 0, -1, 0, 0);

		cout << ans << '\n';
	}

	return 0;
}