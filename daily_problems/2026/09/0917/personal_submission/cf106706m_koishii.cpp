#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<long long> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	long long ans = 1LL * (n - 1) * n / 2 - 1;
	auto f = [&]() -> void {
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			ans = std::max(ans, sum - a[i]);
			sum += a[i];
		}
	};
	f();
	std::reverse(a.begin() + 1, a.end());
	f();
	std::cout << ans << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
