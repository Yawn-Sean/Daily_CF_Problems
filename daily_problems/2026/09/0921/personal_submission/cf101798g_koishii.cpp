#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<long long> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());

	long long ans = 0;

	auto sol = [&](auto&& self, int l, int r) -> void {
		if (l >= r) return;
		for (int i = l, j = r; i < j; i++, j--) {
			ans += a[j] - a[i];
		}
		int mid = l + r >> 1;
		self(self, mid + 1, r);
	};

	sol(sol, 1, n);

	std::cout << ans << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
