#include <bits/stdc++.h>
using namespace std;

const long double pi = std::acos(-1);

void soviet() {
	long long r, l, th; std::cin >> r >> l >> th;
	long double w = 2.0 * r * std::sin(th / 180.0 * pi / 2);
	std::cout << std::fixed << std::setprecision(10) << std::sqrt(l * l - w * w) << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
