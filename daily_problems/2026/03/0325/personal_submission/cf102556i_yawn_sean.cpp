#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	vector<vector<int>> pre(n, vector<int>(n, 0));

	auto is_in = [&] (int to_check, int i, int j, int k) -> bool {
		auto [x, y] = pts[to_check];
		auto [x1, y1] = pts[i];
		auto [x2, y2] = pts[j];
		auto [x3, y3] = pts[k];

		return (x2 - x1) * (y - y1) > (x - x1) * (y2 - y1) &&
				(x3 - x2) * (y - y2) > (x - x2) * (y3 - y2) &&
				(x1 - x3) * (y - y3) > (x - x3) * (y1 - y3);
	};

	for (int i = 1; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			for (int k = 1; k < n; k ++) {
				if (k != i && k != j && (is_in(k, 0, i, j) || is_in(k, 0, j, i))) {
					pre[i][j] ++;
				}
			}
		}
	}

	auto area = [&] (int x, int y) -> int {
		int x1 = pts[x].first - pts[0].first;
		int y1 = pts[x].second - pts[0].second;
		int x2 = pts[y].first - pts[0].first;
		int y2 = pts[y].second - pts[0].second;
		return x1 * y2 > x2 * y1 ? pre[x][y] : -pre[x][y];
	};

	long long ans = 0;

	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			for (int k = j + 1; k < n; k ++) {
				int cnt = abs(area(i, j) + area(j, k) - area(i, k));

				if (is_in(0, i, j, k) || is_in(0, i, k, j)) cnt ++;
				else if (is_in(i, 0, j, k) || is_in(i, 0, k, j)) cnt --;
				else if (is_in(j, 0, i, k) || is_in(j, 0, k, i)) cnt --;
				else if (is_in(k, 0, i, j) || is_in(k, 0, j, i)) cnt --;

				ans += cnt * (cnt - 1) * (cnt - 2) / 6;
			}
		}
	}

	cout << ans;

	return 0;
}