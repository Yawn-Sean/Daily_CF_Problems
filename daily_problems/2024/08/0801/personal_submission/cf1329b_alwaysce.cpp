#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		i64 d, m;
		std::cin >> d >> m;		
		i64 ans = 1ll;
		for (int i = 0; i < 32; i++) {
			if (d < (1 << i)) {
				break;
			}
			// msb=i的数字最多只能取一个/或者不取
			i64 lo = (1ll << i);
			i64 hi = std::min((1ll << (i + 1)) - 1ll, d);
			ans = (ans + m) % m;
			ans *= (hi - lo + 2ll) % m;
		}
		ans--; //去掉空的
		ans += m;
		std::cout << ans % m << '\n';
	}
	return 0;
}
