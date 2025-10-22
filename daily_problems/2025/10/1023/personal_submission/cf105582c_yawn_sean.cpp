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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, mi, ma;
	cin >> n >> mi >> ma;

	vector<pair<int, int>> items(n);
	for (auto &[x, y]: items) cin >> x >> y;

	int l = 1, r = 1e6, M = 1e4;

	while (l <= r) {
		int mid = (l + r) / 2;

		vector<int> dp(M + 1, 0);
		dp[0] = 1;

		for (auto &[x, y]: items) {
			int m = x, c = y / mid;

			for (int j = 0; j < m; j ++) {
				long long bound = -1;
				for (int x = j; x <= M; x += m) {
					if (dp[x]) bound = max(bound, x + 1ll * c * m);
					if (x <= bound) dp[x] = 1;
				}
			}
		}

		bool flg = false;
		for (int i = mi; i <= ma; i ++)
			if (dp[i]) flg = true;
		
		if (flg) l = mid + 1;
		else r = mid - 1;
	}

	cout << r;

	return 0;
}