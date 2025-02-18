#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve(){
	int n, m, k;
	std::cin >> n >> m >> k;

	i64 res = 0;

	auto f = [&](int x) -> int {
		return m / std::max(1, (x + 1));
	};

	for (int i = 1; i <= n && i <= 40000; ++ i) {
		res = std::max(res, 1LL * i * f(k - n / i + 1));
		res = std::max(res, 1LL * n / i * f(k - n / (n / i) + 1));
	}

	std::cout << (res ? res : -1);
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