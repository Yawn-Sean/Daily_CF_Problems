#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
		关键在于每个人都只需要考虑自己的颜色c
		第i个人拿了x个c
		第j个人拿了y个d 不会对于i产生影响(其他颜色不会影响之前人别的颜色的选择)
		
		每个颜色应该尽量拿满
		统计喜欢颜色c的人数player_cnt[c] = i
		对于这i个人 拿j个颜色c 的最大值就是dp[i][j]
		每一种颜色又是独立的(一个人不会同时喜欢两个颜色)
		所以按照颜色+喜欢人数累加dp结果就好
	*/
	int n, k;
	cin >> n >> k;
	
	int M = 1e5;
	vector<int> cnt(M + 1);
	for (int i = 0; i < n * k; i++) {
		int c;
		cin >> c;
		cnt[c]++;
	}
	
	vector<int> player_cnt(M + 1);
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		player_cnt[c]++;
	}
	
	vector<int> hs(k);
	for (auto& h: hs) {
		cin >> h;
	}
	
	// dp[i][j]: 前i人使用(某种颜色) j张卡的最大收益
	vector<vector<int>> dp(n + 1, vector<int>(n * k + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = n * k; j > 0; j--) {
			for (int v = 0; v < k; v++) {
				if (j - v - 1 >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - v - 1] + hs[v]);
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= M; i++) {
		ans += dp[player_cnt[i]][cnt[i]];
	}
	cout << ans;
	return 0;
}
