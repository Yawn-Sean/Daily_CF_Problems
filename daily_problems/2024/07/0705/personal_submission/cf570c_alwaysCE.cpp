#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		char ch;
		std::cin >> ch;
		a[i] = (ch == '.');
	}
	
	int tot = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] and a[i + 1]) {
			tot++;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int x;
		char ch;
		std::cin >> x >> ch;
		int y = (ch == '.');
		if (a[x] != y) {
			if (y) {
				tot += (a[x - 1] + a[x + 1]);
			} else {
				tot -= (a[x - 1] + a[x + 1]);
			}
		}
		std::cout << tot << '\n';
		a[x] = y;
	}
	return 0;
}
