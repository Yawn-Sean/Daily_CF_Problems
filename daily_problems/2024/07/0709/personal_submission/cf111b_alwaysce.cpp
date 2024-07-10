#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int M = 1e5;
	std::vector<int> prime_fact(M + 1);
	std::iota(prime_fact.begin(), prime_fact.end(), 0);
	for (int i = 2; i <= M; i++) {
		if (prime_fact[i] == i) {
			for (int j = i; j <= M; j += i) {
				prime_fact[j] = i;//j的最小质因子
			}
		}
	}
	
	int n;
	std::cin >> n;
	std::vector<int> last_vis(M + 1, -1);
	// 获取x的因子
	auto fac = [&](int x) {
		std::vector<int> res = {1};
		while (x > 1) {
			int p = prime_fact[x];
			int k = (int)res.size();
			while (x % p == 0) {
				for (int i = 0; i < k; i++) {
					res.push_back(res[res.size() - k] * p);
				}
				x /= p;
			}
		}
		return res;
	};
	
	for (int i = 0; i < n; i++) {
		int ans = 0;
		int x, y;
		std::cin >> x >> y;
		
		for (auto& f: fac(x)) {
			ans += ((i - last_vis[f]) > y);
			last_vis[f] = i;
		}
		std::cout << ans << '\n';
	}
	return 0;
}
