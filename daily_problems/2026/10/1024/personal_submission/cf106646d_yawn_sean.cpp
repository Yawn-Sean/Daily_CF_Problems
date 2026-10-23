#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, h;
	cin >> n >> h;

	int ans = 0;

	vector<vector<pair<int, int>>> lefts(n), rights(n);

	for (int i = 0; i < n; i ++) {
		int k;
		cin >> k;

		vector<pair<int, int>> polygon(k);
		int mx = -1e9, mn = 1e9;

		for (auto &[x, y]: polygon) cin >> x >> y, mx = max(mx, x), mn = min(mn, x);
		ans += mx - mn;

		{
			int idx = min_element(polygon.begin(), polygon.end(), [&] (pair<int, int> &x, pair<int, int> &y) {
				return make_pair(x.second, x.first) < make_pair(y.second, y.first);
			}) - polygon.begin();

			vector<pair<int, int>> pts;

			while (true) {
				pts.emplace_back(polygon[idx]);
				if (polygon[idx].second == h) break;
				idx = (idx + k - 1) % k;
			}

			lefts[i] = pts;
		}

		{
			int idx = max_element(polygon.begin(), polygon.end(), [&] (pair<int, int> &x, pair<int, int> &y) {
				return make_pair(x.second, x.first) < make_pair(y.second, y.first);
			}) - polygon.begin();

			vector<pair<int, int>> pts;

			while (true) {
				pts.emplace_back(polygon[idx]);
				if (polygon[idx].second == 0) break;
				idx = (idx + k - 1) % k;
			}
			reverse(pts.begin(), pts.end());

			rights[i] = pts;
		}
	}

	vector<vector<long double>> grid(n, vector<long double>(n, 0));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (i != j) {
				auto left = rights[i];
				auto right = lefts[j];

				int base = min_element(right.begin(), right.end())->first - max_element(left.begin(), left.end())->first;

				long double real = 1e9;

				{
					int pt = 0;

					for (int idx = 0; idx < left.size(); idx ++) {
						while (pt + 1 < right.size() && right[pt + 1].second < left[idx].second) pt ++;

						auto [x, y] = left[idx];
						auto [x1, y1] = right[pt];
						auto [x2, y2] = right[pt + 1];

						long double cur_x = (long double)(x1 * (y2 - y1) + (x2 - x1) * (y - y1)) / (y2 - y1);
						real = min(real, cur_x - x);
					}
				}

				{
					int pt = 0;

					for (int idx = 0; idx < right.size(); idx ++) {
						while (pt + 1 < left.size() && left[pt + 1].second < right[idx].second) pt ++;

						auto [x, y] = right[idx];
						auto [x1, y1] = left[pt];
						auto [x2, y2] = left[pt + 1];

						long double cur_x = (long double)(x1 * (y2 - y1) + (x2 - x1) * (y - y1)) / (y2 - y1);
						real = min(real, x - cur_x);
					}
				}

				grid[i][j] = real - base;
			}
		}
	}

	vector<vector<long double>> dp(n, vector<long double>(1 << n, 0));

	for (int i = 0; i < (1 << n); i ++) {
		for (int j = 0; j < n; j ++) {
			if (i >> j & 1) {
				for (int k = 0; k < n; k ++) {
					if (i >> k & 1) continue;
					dp[k][i | (1 << k)] = max(dp[k][i | (1 << k)], dp[j][i] + grid[j][k]);
				}
			}
		}
	}

	long double max_saved = 0;

	for (auto &x: dp) max_saved = max(max_saved, x.back());

	cout << fixed << setprecision(15) << ans - max_saved;

	return 0;
}