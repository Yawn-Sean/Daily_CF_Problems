#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, k; std::cin >> n >> k;
	std::vector<int> t(n + 1), f(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> t[i] >> f[i];
	}

	std::vector<int> p(k + 1), d(k + 1), c(k + 1);
	for (int i = 1; i <= k; i++) {
		std::cin >> p[i] >> d[i] >> c[i];
	}

	std::vector<long long> dp(n + 1, 1e18);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + f[i];
		for (int j = 1; j <= k; j++) {
			int id = std::lower_bound(t.begin() + 1, t.end(), t[i] - p[j] + 1) - t.begin();
			id = std::max(id, i - d[j] + 1);
			dp[i] = std::min(dp[i], dp[id - 1] + c[j]);
		}
	}
	std::cout << dp[n];
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
