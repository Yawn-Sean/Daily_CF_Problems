#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, h;
	std::cin >> n >> h;
	
	std::vector<int> ls(n), rs(n);
	for (int i = 0; i < n; i++) {
		std::cin >> ls[i] >> rs[i];
	}
	
	int l = 0, r = 0;
	int ans = 0;
	int cur = h, tot = 0;
	
	while (l < n) {
		while (r < n - 1 and ls[r + 1] - rs[r] < cur) {
			tot += rs[r] - ls[r];
			cur -= ls[r + 1] - rs[r];
			r++;
		}
		ans = std::max(ans, tot + rs[r] - ls[r] + h);
		tot -= (rs[l] - ls[l]);
		l++;
		if (l < n) {
			cur += ls[l] - rs[l - 1];
		}
	}
	std::cout << ans << '\n';
	return 0;
}
