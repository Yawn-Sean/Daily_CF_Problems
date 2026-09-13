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

	int t;
	cin >> t;

	long long inf = 1e18;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<vector<long long>> dis(n, vector<long long>(n, inf));

		for (int i = 0; i < n; i ++) dis[i][i] = 0;

		while (m --) {
			int u, v;
			long long w;
			cin >> u >> v >> w;
			u --, v --;

			dis[u][v] = min(dis[u][v], w);
			dis[v][u] = min(dis[v][u], w);
		}

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				for (int k = 0; k < n; k ++) {
					dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
				}
			}
		}

		int a, b;
		cin >> a >> b;

		vector<array<long long, 3>> alice(a), bob(b);
		for (auto &[s, e, l]: alice) cin >> s >> e >> l, l --;
		for (auto &[s, e, l]: bob) cin >> s >> e >> l, l --;

		long long ans = 0;
		int pta = 0, ptb = 0;

		while (pta + 1 < a && ptb + 1 < b) {
			long long l1 = alice[pta][1], r1 = alice[pta + 1][0];
			int s1 = alice[pta][2], t1 = alice[pta + 1][2];

			long long l2 = bob[ptb][1], r2 = bob[ptb + 1][0];
			int s2 = bob[ptb][2], t2 = bob[ptb + 1][2];

			long long res = 0;
			for (int i = 0; i < n; i ++) {
				long long l = max(l1 + dis[s1][i], l2 + dis[s2][i]);
				long long r = min(r1 - dis[i][t1], r2 - dis[i][t2]);
				res = max(res, r - l);
			}

			ans += res;

			if (r1 < r2) pta ++;
			else ptb ++;
		}

		cout << ans << '\n';
	}

	return 0;
}