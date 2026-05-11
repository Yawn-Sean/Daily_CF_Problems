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

	int n, m, q;
	cin >> n >> m >> q;

	vector<array<int, 4>> edges(m);
	for (auto &[u, v, p, h]: edges) {
		cin >> u >> v >> p >> h;
		u --, v --;
	}

	sort(edges.begin(), edges.end(), [&] (array<int, 4> &x, array<int, 4> &y) {return x[2] < y[2];});

	long long inf = 1e13;

	vector<vector<long long>> dis(n, vector<long long>(n, inf)), saved(n);

	for (int i = 0; i < n; i ++) dis[i][i] = 0;

	for (auto &[u, v, p, h]: edges) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				dis[i][j] = min(dis[i][j], dis[i][u] + h + dis[v][j]);
			}
		}

		for (int i = 0; i < n; i ++) {
			saved[i].emplace_back(*max_element(dis[i].begin(), dis[i].end()));
		}
	}

	for (auto &x: saved) reverse(x.begin(), x.end());

	reverse(edges.begin(), edges.end());

	auto min_saved = saved;

	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			min_saved[i][j] = min(min_saved[i][j], min_saved[i - 1][j]);
		}
	}

	while (q --) {
		int t;
		cin >> t;

		if (t == 1) {
			int u;
			long long h;
			cin >> u >> h;
			u --;

			int l = 0, r = m - 1;

			while (l <= r) {
				int mid = (l + r) / 2;

				if (saved[u][mid] > h) r = mid - 1;
				else l = mid + 1;
			}

			if (r < 0) cout << -1 << '\n';
			else cout << edges[r][2] << '\n';
		}
		else {
			long long h;
			cin >> h;

			int l, r;

			l = 0, r = m - 1;

			while (l <= r) {
				int mid = (l + r) / 2;

				if (min_saved[n - 1][mid] > h) r = mid - 1;
				else l = mid + 1;
			}

			if (r < 0) cout << -1 << ' ' << -1 << '\n';
			else {
				int saved_r = r;
				l = 0;

				while (l <= r) {
					int mid = (l + r) / 2;
					
					if (edges[mid][2] == edges[saved_r][2]) r = mid - 1;
					else l = mid + 1; 
				}

				int pos = l;

				l = 0, r = n - 1;

				while (l <= r) {
					int mid = (l + r) / 2;

					if (min_saved[mid][pos] <= h) r = mid - 1;
					else l = mid + 1;
				}

				cout << l + 1 << ' ' << edges[pos][2] << '\n';
			}
		}
	}

	return 0;
}