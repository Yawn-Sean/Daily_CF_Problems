#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long inf = 2e18;

	while (true) {
		int n, u, v;
		cin >> n >> u >> v;

		if (!n && !u && !v) break;

		int m;
		cin >> m;

		vector<int> xs = {1, u, n}, ys = {1, v, n};
		vector<array<int, 4>> recs(m);

		for (auto &[x1, x2, y1, y2]: recs) {
			cin >> x1 >> x2 >> y1 >> y2;

			if (x1 - 1 >= 1) xs.emplace_back(x1 - 1);
			xs.emplace_back(x1);
			xs.emplace_back(x2);
			if (x2 + 1 <= n) xs.emplace_back(x2 + 1);

			if (y1 - 1 >= 1) ys.emplace_back(y1 - 1);
			ys.emplace_back(y1);
			ys.emplace_back(y2);
			if (y2 + 1 <= n) ys.emplace_back(y2 + 1);
		}

		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());

		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());

		int N = xs.size(), M = ys.size();

		vector<vector<int>> grid(N, vector<int>(M, 0));

		for (auto &[x1, x2, y1, y2]: recs) {
			int px1 = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
			int px2 = lower_bound(xs.begin(), xs.end(), x2 + 1) - xs.begin();

			int py1 = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
			int py2 = lower_bound(ys.begin(), ys.end(), y2 + 1) - ys.begin();

			grid[px1][py1] ++;
			if (px2 < N) grid[px2][py1] --;
			if (py2 < M) grid[px1][py2] --;
			if (px2 < N && py2 < M) grid[px2][py2] ++;
		}

		for (int i = 0; i < N; i ++) {
			for (int j = 1; j < M; j ++) {
				grid[i][j] += grid[i][j - 1];
			}
		}

		for (int i = 1; i < N; i ++) {
			for (int j = 0; j < M; j ++) {
				grid[i][j] += grid[i - 1][j];
			}
		}

		vector<vector<long long>> dis(N, vector<long long>(M, inf));

		int sx = lower_bound(xs.begin(), xs.end(), u) - xs.begin();
		int sy = lower_bound(ys.begin(), ys.end(), v) - ys.begin();

		dis[sx][sy] = 0;

		priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> pq;
		
		pq.push({0, sx, sy});

		while (!pq.empty()) {
			auto [d, x, y] = pq.top(); pq.pop();

			if (dis[x][y] == d) {
				if (x && grid[x - 1][y] == 0) {
					long long nd = d + xs[x] - xs[x - 1];
					if (dis[x - 1][y] > nd) {
						dis[x - 1][y] = nd;
						pq.push({dis[x - 1][y], x - 1, y});
					}
				}

				if (x + 1 < N && grid[x + 1][y] == 0) {
					long long nd = d + xs[x + 1] - xs[x];
					if (dis[x + 1][y] > nd) {
						dis[x + 1][y] = nd;
						pq.push({dis[x + 1][y], x + 1, y});
					}
				}

				if (y && grid[x][y - 1] == 0) {
					long long nd = d + ys[y] - ys[y - 1];
					if (dis[x][y - 1] > nd) {
						dis[x][y - 1] = nd;
						pq.push({dis[x][y - 1], x, y - 1});
					}
				}

				if (y + 1 < M && grid[x][y + 1] == 0) {
					long long nd = d + ys[y + 1] - ys[y];
					if (dis[x][y + 1] > nd) {
						dis[x][y + 1] = nd;
						pq.push({dis[x][y + 1], x, y + 1});
					}
				}
			}
		}

		int q;
		cin >> q;

		while (q --) {
			int x, y;
			cin >> x >> y;

			int pxl = upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
			int pyl = upper_bound(ys.begin(), ys.end(), y) - ys.begin() - 1;

			int pxr = (pxl + 1 < N && grid[pxl + 1][pyl] == 0) ? pxl + 1 : pxl;
			int pyr = (pyl + 1 < M && grid[pxl][pyl + 1] == 0) ? pyl + 1 : pyl;

			long long ans = inf;

			for (int i = pxl; i <= pxr; i ++) {
				for (int j = pyl; j <= pyr; j ++) {
					if (grid[i][j] == 0) {
						ans = min(ans, dis[i][j] + abs(xs[i] - x) + abs(ys[j] - y));
					}
				}
			}

			if (ans < inf) cout << ans << '\n';
			else cout << "no\n";
		}
	}

	return 0;
}