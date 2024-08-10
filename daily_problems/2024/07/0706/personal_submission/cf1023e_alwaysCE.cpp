#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

bool query(int x1, int y1, int x2, int y2) {
	std::cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << std::endl;
	std::string ans;
	std::cin >> ans;
	return (ans == "YES");
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	int x = 1, y = 1;
	std::vector<char> tmp1;
	for (int i = 0; i < n - 1; i++) {
		if (query(x, y + 1, n, n)) {
			y++;
			tmp1.push_back('R');
		} else {
			x++;
			tmp1.push_back('D');
		}
	}
	
	x = n, y = n;
	std::vector<char> tmp2;
	for (int i = 0; i < n - 1; i++) {
		if (query(1, 1, x - 1, y)) {
			x--;
			tmp2.push_back('D');
		} else {
			y--;
			tmp2.push_back('R');
		}
	}
	std::reverse(tmp2.begin(), tmp2.end());
	std::cout << "! ";
	for (auto& c: tmp1) {
		std::cout << c;
	}
	for (auto& c: tmp2) {
		std::cout << c;
	}
	return 0;
}
