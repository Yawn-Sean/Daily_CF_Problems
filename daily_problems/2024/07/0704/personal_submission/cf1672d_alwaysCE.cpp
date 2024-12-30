#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	
	while (t--) {
		int n;
		std::cin >> n;
		
		std::vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		
		std::vector<int> saved(n + 1);
		int pt = 0;
		
		for (auto &x: a) {
			if (x == b[pt]) { 
				pt++;
			}
			else {
				saved[x]++; // a里面的数字存起来
			}
			// 发现可能可以操作! 尽可能操作b
			while (pt > 0 and pt < n and b[pt] == b[pt - 1] and saved[b[pt]]) {
				saved[b[pt]]--;
				pt++;
			}
		}
		
		std::cout << ((pt == n) ? "YES" : "NO") << '\n';
	}
	return 0;
}
