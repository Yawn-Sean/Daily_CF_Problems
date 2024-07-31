#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::vector<i64> cnt(5001);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cnt[abs(a[i] - a[j])]++;
		}
	}
	
	std::vector<i64> cnt2(5001);
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; i + j < 5000; j++) {
			// roll两次产生的差
			cnt2[i + j] += cnt[i] * cnt[j];
		}
	}
	
	for (int i = 1; i <= 5000; i++) {
		cnt2[i] += cnt2[i - 1];
	}
	
	i64 ans = 0;
	for (int i = 1; i <= 5000; i++) {
		ans += cnt2[i - 1] * cnt[i];
	}
	
	std::cout << std::setprecision(15) << 1.0 * ans / std::pow(1.0 * n * (n - 1) / 2, 3);
	return 0;
}
