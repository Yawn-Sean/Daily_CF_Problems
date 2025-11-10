#include <bits/stdc++.h>
using namespace std;

void soviet() {
	long long c; std::cin >> c;
	std::cout << c << ' ' << (c << int(std::log2(c) + 1)) << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
