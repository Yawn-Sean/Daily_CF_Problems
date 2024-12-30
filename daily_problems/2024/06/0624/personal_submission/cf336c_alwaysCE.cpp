#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 100000007;
i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	/*
		枚举bit位置
		a1 & a2 & a3 = 2^v
		a1,a2,a3都在v位=1
		其他位置至少有一个0 
		
	*/
	for (int v = 29; v >= 0; v--) {
		std::vector<int> check;
		
		for (int i = 0; i < n; i++) {
			if ( ((a[i] >> v) & 1) == 1 ) {
				check.push_back(i);
			}	
		}
		
		bool ok = true;
		for (int pre = v - 1; pre >= 0; pre--) {
			bool find = false;
			for (auto& i: check) {
				if ( ((a[i] >> pre) & 1) == 0 ) {
					find = true;
					break;
				}
			}
			if (!find) {
				ok = false;
				break;
			}
		}
		
		if (ok) {
			std::cout << check.size() << '\n';
			for (auto& i: check) {
				std::cout << a[i] << ' ';
			}
			return 0;
		}
	}
	
	std::cout << -1 << '\n';
	return 0;
}
