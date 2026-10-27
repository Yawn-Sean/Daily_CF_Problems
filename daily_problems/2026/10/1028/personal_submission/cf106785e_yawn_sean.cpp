#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<string> grid(n);
		for (auto &s: grid) cin >> s;

		vector<vector<int>> dp0(n, vector<int>(m, 0));
		vector<vector<int>> dp1(n, vector<int>(m, 0));
		dp0[0][0] = (grid[0][0] == '.' ? 1 : 0);

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (grid[i][j] == '.') {
					if (i) dp0[i][j] += dp0[i - 1][j];
					if (j) {
						if (i && grid[i][j - 1] == '#') dp0[i][j] += dp1[i - 1][j];
						dp1[i][j] = dp0[i][j - 1] + dp1[i][j - 1];
					}
					dp0[i][j] %= mod;
					dp1[i][j] %= mod;
				}
			}
		}

		cout << (dp0[n - 1][m - 1] + dp1[n - 1][m - 1]) % mod << '\n';
	}

	return 0;
}