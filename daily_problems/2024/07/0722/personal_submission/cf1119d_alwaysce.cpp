#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::vector<i64> pre(n + 1);
	
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1] - a[i];
	}
	a[n - 1] = 1e18;
	a[n - 1] += 1ll;
	
	std::sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i];
	}
	
	int q;
	std::cin >> q;
	while (q--) {
		i64 l, r;
		std::cin >> l >> r;
		
		i64 x = r - l + 1;
		auto it = std::lower_bound(a.begin(), a.end(), x);
		int idx = (it - a.begin());
		i64 res = pre[idx] + x * ((i64)n - (i64)idx);
		std::cout << res << ' ';
	}
	
	return 0;
}
