#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::function<void(int,int)> print_ans = [&](int n, int x) {
		if (n <= 3) {
			for (int i = 0; i < n - 1; i++) {
				std::cout << x << ' ';
			}
			std::cout <<  n * x << '\n';
		} else {
			for (int i = 0; i < n - (n / 2); i++) {
				std::cout << x << ' ';
			}
			print_ans(n / 2, x * 2);
		}
	};
	
	print_ans(n, 1);
	return 0;
}
