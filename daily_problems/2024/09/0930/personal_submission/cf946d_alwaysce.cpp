#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<string> ke(n);
	for (int i = 0; i < n; i++) {
		cin >> ke[i];
	}
	
	vector<vector<int>> qiao(n, vector<int>(k + 1, 0));
	
	auto cal = [&](int idx, int cnt) {
		int cur = 0;
		for (int i = 0; i < m; i++) {
			if (ke[idx][i] == '1') {
				++cur;
			}
		}
		if (cur <= cnt) {
			return 0;
		}
		
		int cur_cnt = 0;
		cur = cur - cnt; // 还需要上的课数量
		// cout << cur << '\n';
		int l = 0;
		int ans = m;
		for (int r = 0; r < m; r++) {
			cur_cnt += (ke[idx][r] == '1');
			while (l <= r and cur_cnt == cur) {
				ans = min(ans, r - l + 1);
				cur_cnt -= (ke[idx][l] == '1');
				l++;
			}
			// cout << l << ' ' << r << '\n';
			// [l, r]
		}
		return ans;
	};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			qiao[i][j] = cal(i, j);
			// cout << i << ' ' << j <<  ' ' << qiao[i][j] << '\n';
		}	
	}
	
	// 前i天 翘了j次的最小学习时间
	vector<vector<int>> dp(n, vector<int>(k + 1, n * m));
	for (int j = 0; j <= k; j++) {
		dp[0][j] = qiao[0][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][l] + qiao[i][j - l]);
			}
		}
	}
	
	cout << dp[n - 1][k];
	return 0;
}
