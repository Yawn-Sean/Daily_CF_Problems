#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 100000007;
i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 A, B, n;
	std::cin >> A >> B >> n;
	
	
	for (int i = 0; i < n; i++) {
		i64 l, t, m;
		std::cin >> l >> t >> m;
		
		
		std::function<bool(i64)> check = [&](i64 x) -> bool {	
			i64 st = A + (l - 1) * B;
			i64 ed = A + (x - 1) * B;
			// 区间和 <= tm and 区间最大值不能超过t
			i64 tot = (st + ed) * (x - l + 1) / 2;
			return (tot <= t * m) and (ed <= t);
		};
	
		i64 res = -1;
		i64 left = l, right = l + t * m;
		while (left < right) {
			i64 mid = left + (right - left) / 2;
			if (check(mid)) {
				res = mid;
				left = mid + 1;	
			} else {
				right = mid;
			}
		}
		std::cout << res << '\n';
	}
	return 0;
}
