#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v1(n), v2(n);

	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	int ans = 0, mod = 1e9 + 7;

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	for (int bit = 0; bit < 30; bit ++) {
		vector<vector<int>> grid(n, vector<int>(n));

		for (int x = 0; x < n; x ++) {
			for (int y = 0; y < n; y ++) {
				grid[x][y] = (v1[x] + v2[y]) >> bit & 1;
			}
		}

		vector<vector<int>> dp(2, vector<int>(1 << n, 0));
		dp[0][0] = 1 << bit;

		for (int msk = 0; msk < 1 << n; msk ++) {
			int x = __popcount(msk);

			for (int y = 0; y < n; y ++) {
				if (msk >> y & 1) continue;
				for (int i = 0; i < 2; i ++) {
					add(dp[i ^ grid[x][y]][msk | (1 << y)], dp[i][msk]);
				}
			}
		}

		add(ans, dp[1][(1 << n) - 1]);
	}

	cout << ans;

	return 0;
}