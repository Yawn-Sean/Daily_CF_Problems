#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, x;
	std::cin >> n >> x;
	int l = x, r = x;
	i64 ans = 0;
	
	for (int i = 0; i < n; i++) {
		int ls, rs;
		std::cin >> ls >> rs;
		if (r < ls) {
			ans += ls - r;
			l = r;
			r = ls;
		} else if (l > rs) {
			ans += l - rs;
			r = l;
			l = rs;
		} else {
			l = std::max(l, ls);
			r = std::min(r, rs);
		}
	}
	std::cout << ans << '\n';
	return 0;
}
