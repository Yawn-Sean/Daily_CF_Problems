#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef pair<int, int> pt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	auto sign = [&] (pt v) -> bool {
		return v.second > 0 || (v.second == 0 && v.first > 0);
	};

	int n, mod = 998244353;
	cin >> n;

	vector<pt> pts_pos, pts_neg;

	for (int i = 0; i < n; i ++) {
		pt v;
		cin >> v.first >> v.second;
		if (sign(v)) pts_pos.emplace_back(v);
		else pts_neg.emplace_back(v);
	}

	sort(pts_pos.begin(), pts_pos.end(), [&] (pt &x, pt &y) {
		return 1ll * x.second * y.first < 1ll * x.first * y.second;
	});
	sort(pts_neg.begin(), pts_neg.end(), [&] (pt &x, pt &y) {
		return 1ll * x.second * y.first < 1ll * x.first * y.second;
	});

	vector<pt> pts;
	pts.insert(pts.end(), pts_pos.begin(), pts_pos.end());
	pts.insert(pts.end(), pts_neg.begin(), pts_neg.end());

	auto check = [&] (int i, int j) -> bool {
		auto [x1, y1] = pts[i];
		auto [x2, y2] = pts[j];

		long long target = 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1);
		long long v1 = 1ll * x1 * x1 + 1ll * y1 * y1;
		long long v2 = 1ll * x2 * x2 + 1ll * y2 * y2;

		return target > v1 && target > v2;
	};

	vector<vector<bool>> saved(n, vector<bool>(n));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			saved[i][j] = check(i, j);
		}
	}

	vector<long long> ans(5);

	for (int i = 0; i < n; i ++) {
		vector<vector<long long>> dp(5, vector<long long>(n, 0));
		dp[0][i] = 1;

		for (int x = i; x < i + n; x ++) {
			int oj = x % n;
			for (int v = 3; v >= 0; v --) {
				if (dp[v][oj]) {
					for (int y = x + 1; y < i + n; y ++) {
						int nj = y % n;
						if (saved[oj][nj]) dp[v + 1][nj] += dp[v][oj];
					}
				}
			}
		}

		for (int x = 0; x < 5; x ++) {
			for (int y = 0; y < n; y ++) {
				if (saved[i][y]) {
					ans[x] += dp[x][y];
				}
			}
		}
	}

	long long res = n;
	for (int i = 1; i < 5; i ++) res += ans[i] / (i + 1);

	cout << res % mod;

	return 0;
}