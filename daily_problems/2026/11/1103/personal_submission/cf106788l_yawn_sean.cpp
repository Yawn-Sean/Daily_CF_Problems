#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	int inf = 1e5;
	vector<vector<int>> dp(1001, vector<int>(1 << n, inf));

	dp[0][0] = 0;

	for (int msk = 0; msk < (1 << n); msk ++) {
		for (int j = 0; j < n; j ++) {
			if (msk >> j & 1) continue;
			int nmsk = msk | (1 << j);
			for (int k = 0; k <= 1000; k ++) {
				if (dp[k][msk] < inf) {
					int nk, nv;
					nk = k + nums[j];
					nv = max(nk, dp[k][msk]);
					if (nk <= 1000) dp[nk][nmsk] = min(dp[nk][nmsk], nv);

					nk = abs(k - nums[j]);
					nv = max(nk, dp[k][msk]);
					if (nk <= 1000) dp[nk][nmsk] = min(dp[nk][nmsk], nv);
				}
			}
		}
	}

	int ans = inf;
	for (auto &x: dp) ans = min(ans, x.back());

	cout << ans;

	return 0;
}