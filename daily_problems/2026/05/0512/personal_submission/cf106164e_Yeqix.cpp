#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	vector<array<i64, 4>> ver;
	ver.reserve(m);
	for (int i = 1; i <= m; i++)  {
		i64 u, v, p, h;
		cin >> u >> v >> p >> h;
		ver.push_back({u, v, p, h});
	}

	sort(ver.begin(), ver.end(), [&](auto x, auto y) {
		return x[2] < y[2];
	});

	map<i64, i64> mp;
	for (int i = 0; i < m; i++) {
		mp[ver[i][2]] = i;
	}

	vector<vector<i64>> dp(n + 1, vector<i64>(n + 1, inf));
	for (int j = 1; j <= n; j++) {
		dp[j][j] = 0;
	}

	vector save(n + 1, vector<i64>(m));
	for (int i = 0; i < m; i++) {
		auto [u, v, p, h] = ver[i];
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[j][k] = min(dp[j][k], dp[j][u] + dp[v][k] + h);
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				save[j][i] = max(save[j][i], dp[j][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			save[i][j] = min(save[i][j], save[i][j - 1]);
		}
	}

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			i64 u, h;
			cin >> u >> h;
			int ans = -1;
			int l = 0, r = m - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (save[u][mid] <= h) {
					r = mid - 1;
					ans = mid;
				} else {
					l = mid + 1;
				}
			}

			if (ans == -1) {
				cout << ans << "\n";
			} else {
				cout << ver[ans][2] << "\n";
			}
		} else {
			i64 h;
			cin >> h;
			int ans = -1;
			int l = 0, r = m - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				bool T = false;
				for (int i = 1; i <= n; i++) {
					if (save[i][mid] <= h) {
						T = true;
						break;
					}
				}

				if (T) {
					r = mid - 1;
					ans = mid;
				} else {
					l = mid + 1;
				}
			}

			if (ans == -1) {
				cout << "-1 -1\n";
				continue;
			}

			ans = mp[ver[ans][2]];
			for (int i = 1; i <= n; i++) {
				if (save[i][ans] <= h) {
					cout << i << " ";
					break;
				}
			}
			cout << ver[ans][2] << "\n";
		}
	}
	return 0;
}
