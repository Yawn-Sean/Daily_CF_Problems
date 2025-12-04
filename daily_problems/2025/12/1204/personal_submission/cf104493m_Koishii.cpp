#include <bits/stdc++.h>
using namespace std;

const long double pi = std::acos(-1);

void soviet() {
	long long r, n, l; std::cin >> r >> n >> l; 
	long double ans = 0;
	ans += 1.L * l * r * n;
	ans += 1.L * pi * r * r;
	ans += 1.L * l * l / 2 / std::tanl(pi / n) * n / 2;
	std::cout << std::fixed << std::setprecision(12) << ans << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
