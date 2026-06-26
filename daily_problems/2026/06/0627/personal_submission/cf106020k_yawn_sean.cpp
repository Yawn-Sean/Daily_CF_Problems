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

	vector<vector<long long>> dp(20, vector<long long>(20, 0));
	dp[0][0] = 1;

	for (int i = 1; i < 20; i ++) dp[0][i] = i * dp[0][i - 1];

	for (int i = 1; i < 20; i ++) {
		for (int j = 0; j < 20; j ++) {
			if (i + j < 20) {
				dp[i][j] = dp[i - 1][j] * j;
				if (i >= 2) dp[i][j] += dp[i - 2][j + 1] * (i - 1);
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		long long k;
		cin >> n >> k;

		k --;

		int v = min(n, n % 2 + 18);
		vector<int> used(v, 0), res(v, 0);

		int x = v, y = 0;

		for (int i = 0; i < v; i ++) {
			for (int j = 0; j < v; j ++) {
				if (used[j] || j == i) continue;

				int nx, ny;
				if (used[i] && j < i) nx = x, ny = y - 1;
				else if (used[i] || j < i) nx = x - 1, ny = y;
				else nx = x - 2, ny = y + 1;

				if (dp[nx][ny] <= k) k -= dp[nx][ny];
				else {
					x = nx;
					y = ny;
					used[j] = 1;
					res[i] = j;
					break;
				}
			}
		}

		for (int i = 0; i < (n - v) / 2; i ++) cout << 2 * i + 2 << ' ' << 2 * i + 1 << ' ';
		for (int i = 0; i < v; i ++) cout << res[i] + n - v + 1 << " \n"[i == v - 1];
	}

	return 0;
}