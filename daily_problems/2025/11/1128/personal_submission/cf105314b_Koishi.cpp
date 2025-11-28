#include <bits/stdc++.h>
using namespace std;


void soviet() {
	long long n, m; std::cin >> n >> m;
	std::vector<long long> a(n + 1), s(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}

	long long ans = 0;

	auto check = [&](int mid) -> bool{
		ans = 0;
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			auto k = std::lower_bound(a.begin() + i + 1, a.end(), a[i] + mid) - a.begin();
			if (k == a.size()) continue;
			cnt += (n - k + 1) << 1;
			ans += (s[n] - s[k - 1] - (n - k + 1) * a[i]) << 1;
		}
		ans -= mid * (cnt - m);
		return cnt >= m;
	};

	int l = 0, r = a[n] - a[1];
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	check(l);
	std::cout << ans << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
