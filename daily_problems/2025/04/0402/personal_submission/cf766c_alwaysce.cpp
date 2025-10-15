#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 1e9 + 7;
int inf = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> lim(26);
	for (int i = 0; i < 26; i++) {
		cin >> lim[i];
	}

	vector<vector<int>> can(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		int j = i;
		vector<int> cnt(26, 0);
		while (j < n) {
			int cur = s[j] - 'a';
			++cnt[cur];
			bool ok = true;
			for (int k = 0; k < 26; k++) {
				if (cnt[k] && j - i + 1 > lim[k]) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				break;
			}	
			can[i][j] = 1;
			++j;
		}
	}

	// 从[0, i)合法方案数
	vector<i64> dp(n + 1, 0);
	dp[0] = 1;
	// max分段长度, min 切割数量
	vector<int> mn_cut(n + 1, inf);
	mn_cut[0] = 0;
	vector<int> mx_len(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (can[j][i - 1]) {
				dp[i] = (dp[i] + dp[j]) % mod;
				mn_cut[i] = min(mn_cut[i], mn_cut[j] + 1);
				mx_len[i] = max(mx_len[i], max(mx_len[j], i - j));
			}
		}
	}

	cout << dp[n] << '\n';
	cout << mx_len[n] << '\n';
	cout << mn_cut[n] << '\n';

	return 0;
}

