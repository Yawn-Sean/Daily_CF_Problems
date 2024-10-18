#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;
	std::cin >> n >> k;
	// 1k 2k 3k ... 
	// 一个集合里面不能有超过2个偶数
	// 每个数都除以k 然后 ak,bk,ck,dk
	// 1 3 5 7 9 11 13 15 17 19
	// 2 4 6  8
	// 每个集合放一个偶数
	// 3个奇数 
	// 2k+1, 2k+3, 2k+5
	
	std::vector<int> base = {1, 2, 3, 5};
	std::cout << (6 * n - 1) * k << '\n';
	for (int i = 0; i < n; i++) {
		for (auto& b: base) {
			std::cout << (6 * i + b) * k << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
