#include <bits/stdc++.h>
using namespace std;

bool sol() {
	long long a, b; std::cin >> a >> b;
	if (a > b) std::swap(a, b);

	if (a == b) {
		if (a & 1) return 0;
		return 1;
	}

	if (a % (b - a) != 0) return 0;
	for (int i = 2; i <= 4; i++) {
		if (b % i == 0) {
			long long x = a - b / i;
			if (x > 0 && b % x == 0) return 1;
		}
	}
	return 0;
}

void soviet() {
	if (sol()) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
