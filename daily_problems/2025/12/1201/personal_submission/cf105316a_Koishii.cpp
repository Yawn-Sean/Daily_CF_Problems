#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void soviet() {
	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) std::cin >> a[i];
	std::vector<long long> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i - 1];
	}
	long long sum = (pref[n] - 1) >> 1;

	std::vector<int> dp(n + 1);
	dp[0] = 1;
	int l = 0, tot = 1;
	for (int i = 1; i <= n; i++) {
		while (pref[i] - pref[l] > sum) {
			tot = (tot - dp[l] + mod) % mod;
			l++;
		}
		dp[i] = tot;
		tot = (tot + dp[i]) % mod;
	}
	std::cout << dp[n];
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
