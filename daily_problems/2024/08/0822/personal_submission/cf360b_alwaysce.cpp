#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	vector<i64> a(n);
	for (auto& v: a) { cin >> v; }
	
	i64 left = 0, right = 2e9;
	auto check = [&](i64 x) {
		vector<int> dp(n, 1);
		// i不变的情况下 前i个元素最大不变的个数
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (abs(a[i] - a[j]) <= x * (i - j)) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) { ans = max(ans, dp[i]); }
		return ans;
	};
	
	while (left < right) {
		i64 mid = (left + right) / 2;
		// 不改的元素+k >= n则满足条件
		if (check(mid) + k < n) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	cout << left << '\n';
	return 0;
}
