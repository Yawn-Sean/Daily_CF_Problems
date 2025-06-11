#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	
	// 左上
	vector<vector<int>> dp0(n, vector<int>(m));
	// 右上
	vector<vector<int>> dp1(n, vector<int>(m));
	// 来自左下
	vector<vector<int>> dp2(n, vector<int>(m));
	// 来自右下
	vector<vector<int>> dp3(n, vector<int>(m));
	
	// D
	for (int i = 0; i < n; i++) {
		// R
		for (int j = m - 1; j >= 0; j--) {
			int x = 0;
			if (i > 0) {
				x = max(x, dp1[i - 1][j]);
			}
			if (j + 1 < m) {
				x = max(x, dp1[i][j + 1]);
			}
			dp1[i][j] = x + grid[i][j];
		}
		// L
		for (int j = 0; j < m; j++) {
			int x = 0;
			if (i > 0) {
				x = max(x, dp0[i - 1][j]);
			}
			if (j > 0) {
				x = max(x, dp0[i][j - 1]);
			}
			dp0[i][j] = x + grid[i][j];
		}
	}
	
	// U
	for (int i = n - 1; i >= 0; i--) {
		// R
		for (int j = m - 1; j >= 0; j--) {
			int x = 0;
			if (i + 1 < n) {
				x = max(x, dp3[i + 1][j]);
			}
			if (j + 1 < m) {
				x = max(x, dp3[i][j + 1]);
			}
			dp3[i][j] = x + grid[i][j];
		}
		// L
		for (int j = 0; j < m; j++) {
			int x = 0;
			if (i + 1 < n) {
				x = max(x, dp2[i + 1][j]);
			}
			if (j > 0) {
				x = max(x, dp2[i][j - 1]);
			}
			dp2[i][j] = x + grid[i][j];
		}
	}
	
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			ans = max(ans, dp0[i - 1][j] + dp1[i][j + 1] + dp2[i][j - 1] + dp3[i + 1][j]);
            ans = max(ans, dp0[i][j - 1] + dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j + 1]);
 		}
	}
	cout << ans;

	return 0;
}
