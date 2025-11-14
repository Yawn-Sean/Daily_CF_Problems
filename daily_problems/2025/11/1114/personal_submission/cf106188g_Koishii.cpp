#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void soviet() {
	int n, k; std::cin >> n >> k;
	int m = 0;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
	}

	std::sort(a.begin() + 1, a.end());

	std::vector dp(m + 2, std::vector<long long> (k));
	dp[0][0] = 1;

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i] + 1; j <= m + 1; j++) {
			ans = (ans + dp[j][k - 1]) % mod;
		}
		for (int j = m + 1; j >= 0; j--) {
			int nj = std::min(j + a[i], m + 1);
			for (int z = k - 2; z >= 0; z--) {
				int nz = z + 1;
				dp[nj][nz] = (dp[nj][nz] + dp[j][z]) % mod;
			}
		}
	}

	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
