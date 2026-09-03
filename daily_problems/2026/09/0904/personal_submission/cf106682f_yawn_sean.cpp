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

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> path(n);

	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(i, v);
		path[v].emplace_back(i, u);
	}

	vector<long double> ans(m, n);

	for (int i = 0; i < m; i ++) {
		deque<int> que = {0};
		vector<int> dis(n, n);
		dis[0] = 0;

		while (!que.empty()) {
			int u = que.front(); que.pop_front();

			for (auto &[eid, v]: path[u]) {
				int nd = dis[u] + (eid >= i);

				if (dis[v] > nd) {
					dis[v] = nd;

					if (eid >= i) que.emplace_back(v);
					else que.emplace_front(v);
				}
			}
		}

		for (int j = i; j < m; j ++)
			ans[j] = min(ans[j], (long double)dis[n - 1] / (j - i + 1));
	}

	cout << fixed << setprecision(10);
	for (auto &x: ans) cout << x << '\n';

	return 0;
}