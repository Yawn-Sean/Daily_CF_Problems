#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	std::vector<int> l(m), r(m);
	
	int ans = n + 5;
	for (int i = 0; i < m; i++) {
		std::cin >> l[i] >> r[i];
		ans = std::min(ans, r[i] - l[i] + 1);
 	}
 	
 	std::cout << ans << '\n'; 	
 	for (int i = 0; i < n; i++) {
 		std::cout << (i % ans) << ' ';
 	}
	std::cout << '\n';
	return 0;
}
