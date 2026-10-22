#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	long double total_ans = 1e9;

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j ++) {
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[j];

			int dx1 = x2 - x1, dy1 = y2 - y1;
			int dx2 = -dy1, dy2 = dx1;

			vector<vector<long long>> grid(n, vector<long long>(n, 0));

			for (int x = 0; x < n; x ++ ){
				for (int y = 0; y < n; y ++) {
					auto [v1, w1] = pts[x];
					auto [v2, w2] = pts[y];
					grid[x][y] += abs(1ll * dx1 * (v1 - v2) + 1ll * dy1 * (w1 - w2));
					grid[x][y] += abs(1ll * dx2 * (v1 - v2) + 1ll * dy2 * (w1 - w2));
				}
			}

			vector<vector<long long>> dp(n, vector<long long>(1 << n, (long long)1e18));

			for (int x = 0; x < n; x ++) dp[x][1 << x] = 0;

			for (int msk = 0; msk < (1 << n); msk ++) {
				for (int x = 0; x < n; x ++) {
					if (msk >> x & 1) {
						for (int y = 0; y < n; y ++) {
							if (msk >> y & 1) continue;
							dp[y][msk | (1 << y)] = min(dp[y][msk | (1 << y)], dp[x][msk] + grid[x][y]);
						}
					}
				}
			}

			long long ans = 1e18;

			for (auto &v: dp) ans = min(ans, v.back());

			total_ans = min(total_ans, ans / hypotl(dx1, dy1));
		}
	}

	cout << fixed << setprecision(15) << total_ans;

	return 0;
}