#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, M;
	cin >> n >> k >> M;
	vector<int> t(k);
	for (auto& x: t) { cin >> x; }
	
	sort(t.begin(), t.end());
	for (int i = 1; i < k; i++) {
		t[i] += t[i - 1];
	}
	
	i64 inf = 1e18;
	vector<i64> dp(n * (k + 1) + 1, inf);
	// 达到当前得分需要的最少的时间
	dp[0] = 0ll;
	
	for (int x = 0; x < n; x++) {
		for (int i = n * (k + 1); i >= 0; i--) {
			for (int j = 0; j < k - 1; j++) {
				if (i - (j + 1) >= 0) {
					dp[i] = min(dp[i], dp[i - (j + 1)] + t[j]);
				}
			}
			if (i >= k + 1) {
				dp[i] = min(dp[i], dp[i - (k + 1)] + t[k - 1]);
			}
		}
	}
	
	for (int i = n * (k + 1); i >= 0; i--) {
		if (dp[i] <= M) {
			cout << i;
			break;
		}
	}
		
	return 0;
}
