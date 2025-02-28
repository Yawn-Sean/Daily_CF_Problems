#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto&x: a) { cin >> x; }
	
	vector<vector<int>> dp(n, vector<int>(5, 0));
	vector<vector<int>> from(n, vector<int>(5, -1));
	
	dp[0][0] = dp[0][1] = 1;
	dp[0][2] = dp[0][3] = 1;
	dp[0][4] = 1;

	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < j; k++) {
					if (dp[i - 1][j] > 0) {
						from[i][k] = j;
						dp[i][k] |= dp[i - 1][j];
					}
				}
			}
		} else if (a[i - 1] < a[i]) {
			for (int j = 0; j < 5; j++) {
				for (int k = j + 1; k < 5; k++) {
					if (dp[i - 1][j] > 0) {
						from[i][k] = j;
						dp[i][k] |= dp[i - 1][j];
					}
				}
			}
		} else {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (j == k) continue;
					if (dp[i - 1][j] > 0) {
						from[i][k] = j;
						dp[i][k] |= dp[i - 1][j];
					}
				}
			}
		}
	}
	
	for (int j = 0; j < 5; j++) {
		if (dp[n - 1][j] > 0) {
			// 找到了一个方案
			vector<int> ans;
			ans.push_back(j+1);
			
			int pt = n - 1;
			int cur = from[pt--][j];
			while (pt >= 0 and cur != -1) {
				ans.push_back(cur + 1);
				cur = from[pt--][cur];
			}
			reverse(ans.begin(), ans.end());
			for (auto&x: ans) {
				cout << x << ' ';
			}
			return 0;
		}
	}
	
	cout << -1;
	return 0;
}
