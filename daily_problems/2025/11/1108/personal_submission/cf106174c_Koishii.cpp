#include <bits/stdc++.h>
using namespace std;

long long f(long long x, long long k) {
	long long ans = 0;
	while (k) {
		long long w = log10(x) + 1;
		long long pw = pow(10, w);
		long long dx = std::min(pw - x, k);
		ans += w * dx;
		k -= dx;
		x = pw;
	}
	return ans;
}

void soviet() {
	long long n, k; std::cin >> n >> k;

	long long l = 1, r = 1e18;
	while (l < r) {
		long long mid = l + r >> 1;
		if (f(mid, n) >= k) r = mid;
		else l = mid + 1;
	}
	if (f(l, n) == k) std::cout << l << '\n';
	else std::cout << -1 << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
