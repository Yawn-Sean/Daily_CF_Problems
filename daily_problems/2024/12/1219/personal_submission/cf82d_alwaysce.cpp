#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		上一次操作 前面剩下的人数 => 发现 剩下的是一个人+一段连续的后缀
	*/
	
	int n;
	cin >> n;
	
	vector<int> nums(n);
	for (auto& v: nums) {
		cin >> v;
	}
	
	int inf = 1e9;
	int mx = n;
	if ((mx & 1) == 0) {
		mx++;
		nums.push_back(0);
	}
	
	// 长度总是一个奇数
	// dp[i][j]: 两个人一组进行dp 剩下一个人对应的最小成本
	vector<vector<int>> dp(n / 2 + 1, vector<int>(mx, inf));
	vector<vector<int>> pre(n / 2 + 1, vector<int>(mx, -1));
	
	dp[0][0] = 0;
	for (int i = 0; i < n / 2; i++) {
		// 枚举剩下来的人j
		// j 2i+1, 2i+2
		for (int j = 0; j <= 2 * i; j++) {
			int v;
			v = max(nums[j], nums[2 * i + 1]) + dp[i][j];
			if (v < dp[i + 1][2 * i + 2]) {
				dp[i + 1][2 * i + 2] = v;
				pre[i + 1][2 * i + 2] = j;
			}
			
			v = max(nums[j], nums[2 * i + 2]) + dp[i][j];
			if (v < dp[i + 1][2 * i + 1]) {
				dp[i + 1][2 * i + 1] = v;
				pre[i + 1][2 * i + 1] = j;
			}
			
			v = max(nums[2 * i + 1], nums[2 * i + 2]) + dp[i][j];
			if (v < dp[i + 1][j]) {
				dp[i + 1][j] = v;
				pre[i + 1][j] = j;
			}
		}
	}
	
	int ans = inf, idx = -1;
	// 剩下来的那个人=idx取到最小?
	for (int i = 0; i < mx; i++) {
		if (dp[n / 2][i] + nums[i] < ans) {
			ans = dp[n / 2][i] + nums[i];
			idx = i;
		}
	}
	cout << ans << '\n';
	
	vector<pair<int,int>> picked;
	picked.emplace_back(idx, n);
	for (int i = n / 2; i > 0; i--) {
		int j = pre[i][idx];
		if (idx == 2 * i - 1) {
			picked.emplace_back(j, 2 * i);
		} else if (idx == 2 * i) {
			picked.emplace_back(j, 2 * i - 1);
		} else {
			picked.emplace_back(2 * i - 1, 2 * i);
		}
		idx = j;
	}
	reverse(picked.begin(), picked.end());
	for (auto& pr: picked) {
		if (pr.first < n) {
			cout << pr.first + 1 << ' ';
		}
		if (pr.second < n) {
			cout << pr.second + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
