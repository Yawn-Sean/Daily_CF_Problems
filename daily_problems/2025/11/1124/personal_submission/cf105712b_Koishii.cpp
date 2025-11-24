#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.rbegin(), a.rend());
	long long ans = 0;

	if (a[0] <= 1) {
		std::cout << 0 << '\n';
	}
	else if (n == 2) {
		auto [x, y] = std::pair{a[0], a[1]};
		while (x > 1 || y > 1) {
			ans += (x / 2) + (y / 2);
			std::tie(x, y) = std::pair{(x & 1) + y / 2, (y & 1) + x / 2};
		}
		std::cout << ans << '\n';
	}
	else {
		for (auto &x: a)  ans += x; 
		if (ans == 3 && a[0] == 3) ans = 1;
		else ans--;

		std::cout << ans << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
