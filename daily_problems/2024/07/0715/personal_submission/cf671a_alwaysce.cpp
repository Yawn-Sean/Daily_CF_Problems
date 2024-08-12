#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
		
	double ax, ay, bx, by, tx, ty, x, y;
	std::cin >> ax >> ay >> bx >> by >> tx >> ty;
	
	auto f = [&]() {
		return std::hypot(x - tx, y - ty);	
	};
	
	auto f1 = [&]() {
		return std::hypot(x - ax, y - ay);	
	};

	auto f2 = [&]() {
		return std::hypot(x - bx, y - by);	
	};
	
	double dp[2][2];
	dp[0][0] = 0.0;
	dp[0][1] = dp[1][0] = dp[1][1] = 4e9;
	
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		
		double v1 = f1() - f();
		double v2 = f2() - f();
		dp[0][0] += 2 * f();
		dp[1][1] = std::min({dp[1][1], dp[1][0] + v2, dp[0][1] + v1});
		dp[1][0] = std::min(dp[1][0], v1);
		dp[0][1] = std::min(dp[0][1], v2);
	}
	
	std::cout << std::setprecision(15) << dp[0][0] + std::min({dp[0][1], dp[1][0], dp[1][1]}) << '\n';
	return 0;
}
