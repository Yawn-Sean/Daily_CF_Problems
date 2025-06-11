#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1E9 + 7;

void solve(){
	int n;
	std::cin >> n;

	int x1, x2;
	std::cin >> x1 >> x2;

	std::vector<std::pair<i64, i64>> p(n);
	for (int i = 0, k, b; i < n; ++ i) {
		std::cin >> k >> b;
		p[i] = {1LL * k * x1 + b, 1LL * k * x2 + b};
	}

	std::ranges::sort(p);

	for (int i = 0; i + 1 < n; ++ i) {
		auto [l1, r1] = p[i];
		auto [l2, r2] = p[i + 1];
		if (r1 > r2) {
			std::cout << "YES";
			return;
		}
	}

	std::cout << "NO";
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main() {
	#ifdef DEBUG
		freopen("in.txt", 'r', stdin);
		freopen("out.txt", 'w', stdout);
	#endif
	int t = 1;
	// std::cin >> t;
	while(t --)
		solve();
	return 0;
}