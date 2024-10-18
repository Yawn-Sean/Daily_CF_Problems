#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<i64> a(n), cnt(15);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		i64 x = a[i], L = 0;
		while (x) {
			x /= 10;
			++L;
		}
		cnt[L]++;
	}
	
	i64 tot = 0;
	for (int i = 0; i < n; i++) {
		i64 cur = a[i];
		i64 tmp = 0;
		// 计算a[i]的贡献
		// a[i]=y放后面
		i64 p = 1;
		for (int j = 1; j <= 10; j++) {
			tmp += (cur % 10) * p % mod; // cur放在0246这些位置上面的贡献
			cur /= 10;
			
			// a[i]多出来的放到前面去的
			if (cur >= 0)
				// cur如果还有则放在前面(隔开一位*10)
				// 加上之前的贡献tmp * cnt[j]
				tot += ((cur * 10) * 10 * p % mod + tmp) * cnt[j] % mod;
			
			p = (p * 100) % mod;
			tot = (tot + mod) % mod;
		}
	
		// a[i]=x放前面
		tmp = 0;
		cur = a[i];
		p = 10;
		for (int j = 1; j <= 10; j++) {
			tmp += (cur % 10) * p % mod;
			cur /= 10;
			
			// a[i]多出来的放到前面去的
			if (cur >= 0)
				// (cur是剩下的 cur*10往前放一位)
				tot += ((cur * 10) * p % mod + tmp) * cnt[j] % mod;
			p = (p * 100) % mod;
			tot = (tot + mod) % mod;
		}
	}
	
	std::cout << tot % mod << '\n';
	return 0;
}
