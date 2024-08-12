#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<i64> cnt(n, 1);
	i64 ans = n;
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		// 每一个子树所组成的区间连续
		// d[x]-1 ! * d[x]
		// n*d[1]!*d[2]!*...*d[n]!
		ans = ((ans * cnt[u]) % mod * cnt[v]) % mod;
		
		cnt[u]++; 
		cnt[v]++;
	}
	std::cout << ans << '\n';
	return 0;
}
