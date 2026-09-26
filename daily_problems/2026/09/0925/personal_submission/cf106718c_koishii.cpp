#include <bits/stdc++.h>
using namespace std;

struct node {
	long long k, d, x;
	bool operator < (const node& e2) const {
		return k > e2.k;
	}
};

void soviet() {
	int n, z; std::cin >> n >> z;
	std::vector<node> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].k >> a[i].d >> a[i].x;
	}
	a.emplace_back(node{0, 1000, 0});
	std::sort(a.begin() + 1, a.end());

	std::vector<long long> dp(z + 1);
	for (int i = 1; i <= z; i++) {
		if (i - a[1].d - 1 < 0) dp[i] = dp[i - 1] + a[1].k;
		else dp[i] = std::max(dp[i - 1] + a[1].k - a[1].x, dp[i - a[1].d - 1] + a[1].k * a[1].d + a[2].k);
	}

	std::cout << dp[z];
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	//std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
