#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::vector<long double> p(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	
	std::sort(p.begin(), p.end());
	std::reverse(p.begin(), p.end());
	
   	long double p0 = 1.0, p1 = 0.0, ans = 0.0;
   	
	for (int i = 0; i < n; i++) {
		// 选>1个人的情况
		// p[i](y - x)要让它最大化
		// 就是说如果选第i个人 可能的new_x
		// => p[i]*(y - x)
		// 即之前的y-x最大的情况下的
		p1 = p1 * (1.0 - p[i]) + p0 * p[i];
		p0 = p0 * (1.0 - p[i]);
		ans = std::max(ans, p1);
	}
	
	std::cout << std::fixed << std::setprecision(12) << ans << '\n';
	return 0;
}
