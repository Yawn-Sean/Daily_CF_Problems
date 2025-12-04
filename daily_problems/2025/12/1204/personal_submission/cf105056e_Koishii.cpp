#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}

	long long ans = 0;
	std::vector<int> stk = {n + 1};
	std::vector<long long> s = {0};

	for (int i = n; i >= 0; i--) {
		while (stk.back() != n + 1 && a[i] > a[stk.back()]) {
			s.pop_back();
			stk.pop_back();
		}
		s.emplace_back(s.back() + 1LL * (stk.back() - i) * a[i]);
		stk.emplace_back(i);
		ans += s.back() - 1LL * (n + 1 - i) * a[i];
	}

	std::cout << ans << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
