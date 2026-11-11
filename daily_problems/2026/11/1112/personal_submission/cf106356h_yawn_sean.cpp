#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<long long> nums(n);
		for (auto &x: nums) cin >> x;

		vector<vector<int>> path(61, vector<int>(61, 0));
		vector<int> vis(61, 0), dp(61, 1);

		for (auto &x: nums) {
			if (x) {
				int k = 63 - __builtin_clzll(x);
				vis[k] = 1;
			}
		}

		for (auto &x: nums) {
			if (x) {
				int k = 63 - __builtin_clzll(x);
				for (int i = 0; i < k; i ++) {
					if ((x >> i & 1) && vis[i]) {
						path[i][k] = 1;
					}
				}
			}
		}

		for (int i = 0; i <= 60; i ++) {
			for (int j = 0; j <= 60; j ++) {
				if (path[i][j]) {
					dp[j] = max(dp[j], dp[i] + path[i][j]);
				}
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}

	return 0;
}