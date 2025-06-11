#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}
	
	// dp[i] = max(dp[i + 1], suf[i + 1] - max(dp[j])), i+1 <= j <= n
	for (int i = n - 2; i > 0; i--) {
		a[i] = std::max(a[i + 1], a[i] - a[i + 1]);		
	}
	std::cout << a[1] << '\n';
	return 0;
}
