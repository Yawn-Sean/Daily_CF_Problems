#include <bits/stdc++.h>
using i64 = long long;

void solve() {
	int n, p, k;
	std::cin >> n >> p >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	sort(a.begin(), a.end());

	std::vector<int> dp(n + 1, 1e9);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i >= k) {
			dp[i] = std::min(dp[i], dp[i - k] + a[i - 1]);
		}
		dp[i] = std::min(dp[i], dp[i - 1] + a[i - 1]);
	}
	int res = 0;
	for (int i = 0; i <= n; i++) {
		if (dp[i] <= p && res < i) res = i;
	}
	std::cout << res << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
    	solve();
    }
}
