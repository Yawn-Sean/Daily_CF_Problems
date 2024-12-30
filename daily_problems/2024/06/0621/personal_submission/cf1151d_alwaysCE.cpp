#include <bits/stdc++.h>

using i64 = long long;

int inf = 1E9;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	
	i64 tot = 0;
	std::vector<i64> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
		tot += b[i] * (n - 1);
		a[i] -= b[i];
	}
	std::sort(a.begin(), a.end());
	for (int i = n - 1; i >= 0; i--) {
		tot +=  a[i] * (n - i - 1);
	}
	std::cout << tot << '\n';
	return 0;	
}
