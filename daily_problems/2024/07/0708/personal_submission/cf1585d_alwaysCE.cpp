#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::map<int,int> mp;
		int mx = 0;
		bool rep = false;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			mx = std::max(mx, a[i]);
			if (mp[a[i]] >= 1) {
				rep = true;
			}
			++mp[a[i]];
		}
		
		if (n == 1) {
			std::cout << "YES\n";
			continue;
		} else if (n == 2) {
			if (a[0] <= a[1]) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
			continue;
		}
		
		if (not rep) {
			Fenwick<i64> f(mx + 1);
			i64 inv = 0;
			for (int i = n - 1; i >= 0; i--) {
				// <= a[i]
				inv += (f.sum(a[i]) & 1);
				f.add(a[i], 1);
			}
			rep = (inv % 2 == 0);
		}
		
		std::cout << (rep ? "YES": "NO") << '\n';
	}
	
	return 0;
}
