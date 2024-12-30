#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 k;
	std::cin >> k;
	
	std::vector<i64> idx(100, 0);
	idx[0] = 0;
	for (int i = 1; i <= 13; i++) {
		idx[i] = idx[i - 1] + 1ll * i * (9 * pow(10, i - 1));
	}
	
	// 0 | 9 | 189 |
	//   [1, 9] | [10,189]
	for (int i = 1; i <= 13; i++) {
		i64 lo = idx[i - 1] + 1;
		i64 hi = idx[i];
		if (lo <= k and k <= hi) {
			// in this range
			k -= lo;
			
			// [lo, hi]
			// 每个数字都是i位长度
			i64 rank = k / i;
			i64 offset = k % i;
			
			// 10 11 12
			// 01 23 45
			i64 base = pow(10, i - 1) + rank;
			std::cout << std::to_string(base)[offset] << '\n';
			return 0;
		}
	}
	return 0;
}
