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

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<array<int, 3>> edges(m);
		for (auto &[u, v, w]: edges) {
			cin >> u >> v >> w;
			u --, v --;
		}

		sort(edges.begin(), edges.end(), [&] (array<int, 3> &x, array<int, 3> &y) {return x[2] < y[2];});

		vector<int> ans(n, n);
		ans[0] = 0;

		int pt = 0;
		while (pt < m) {
			int npt = pt;
			while (npt < m && edges[pt][2] == edges[npt][2])
				npt ++;
			
			vector<pair<int, int>> updates;
			for (int i = pt; i < npt; i ++) {
				auto [u, v, w] = edges[i];
				updates.emplace_back(v, ans[u]);
				updates.emplace_back(u, ans[v] + 1);
			}

			for (auto &[u, d]: updates)
				ans[u] = min(ans[u], d);
			
			pt = npt;
		}

		cout << (ans[n - 1] < n ? ans[n - 1] : -1) << '\n';
	}

	return 0;
}