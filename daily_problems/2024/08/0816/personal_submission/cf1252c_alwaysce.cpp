#include <bits/stdc++.h>
using i64 = long long;

const i64 mod = 1e9 + 7;

int t = 1;

void print_container(const std::vector<int>& c) 
{
    for (int i : c)
        std::cout << i << ' ';
    std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
		
	int n, q;
	std::cin >> n >> q;
	
	std::vector<int> r(n), c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> r[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	
	std::vector<int> p1(n), p2(n);
	// 起点终点都是偶数
	// 中间的每次转移都有奇偶性一致
	// r1->r1+1行 r1c1偶数 r1+1c1也是偶数 等价于r1和r1+1行元素奇偶一致
	for (int i = 1; i < n; i++) {
		p1[i] = (r[i] % 2 == r[i - 1] % 2 ? p1[i - 1]: i);
		p2[i] = (c[i] % 2 == c[i - 1] % 2 ? p2[i - 1]: i);
	}
	
	while (q--) {
		int ra, ca, rb, cb;
		std::cin >> ra >> ca >> rb >> cb;
		--ra; --ca; --rb; --cb;
		
		if (p1[ra] == p1[rb] and p2[ca] == p2[cb]) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
	
	return 0;
}
