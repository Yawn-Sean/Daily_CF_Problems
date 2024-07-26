#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, k;
	std::cin >> n >> k;
	
	if (k * (k + 1) / 2 > n) {
		std::cout << "NO\n";
	} else {
		std::vector<int> ans(k);
		std::iota(ans.begin(), ans.end(), 1);
		n -= k * (k + 1) / 2;
		for (int i = 0; i < k; i++) {
			ans[i] += n / k;
		}	
		n %= k;
		
		for (int i = k - 1; i > 0 and ans[i - 1] != 1 and n > 0; i--) {
			ans[i]++;
			n--;
		}
		ans[k - 1] += n;
		
		for (int i = 0; i < k - 1; i++) {
			if (ans[i] * 2 < ans[i + 1]) {
				std::cout << "NO\n";
				return 0;
			}
		}
		std::cout << "YES\n";
		for (auto& x: ans) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	}
	
	return 0;
}
