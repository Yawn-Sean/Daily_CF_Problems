#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, k;
	std::cin >> n >> k;
	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::sort(a.begin(), a.end());
	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i - 1];
	}
	
	i64 left = 1, right = n + 1;
	i64 l;
	auto check = [&](i64 L){
		for (int i = L - 1; i < n; i++) {
			if (pre[i + 1] - pre[i + 1 - L] + k >= L * a[i]) {
				return true;
			}
		}
		return false;
	};
	
	while (left < right) {
		i64 mid = (left + right) / 2;
		if (check(mid)) {
			l = mid;
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	i64 ans;
	for (int i = l - 1; i < n; i++) {
		if (pre[i + 1] - pre[i + 1 - l] + k >= l * a[i]) {
			ans = a[i];
			break;
		}
	}
	std::cout << l << ' ' << ans << '\n';
	return 0;
}
