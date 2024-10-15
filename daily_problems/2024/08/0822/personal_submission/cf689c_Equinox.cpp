#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

void solve() {
	i64 m;
	std::cin >> m;

	auto f = [&](i64 x) -> i64 {
		i64 s = 0;
		for (i64 i = 2; i * i * i <= x; ++ i)
			s += x / (i * i * i);
		return s;

	};

	i64 lo = 1, hi = m * 8;

	while (lo < hi) {
		i64 x = lo + (hi - lo) / 2;
		if (f(x) >= m) hi = x;
		else lo = x + 1;
	}

	if (f(hi) == m)
		std::cout << hi;
	else
		std::cout << -1;
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main () {
	#ifdef DEBUG
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int T = 1;
	// std::cin >> T;
	while (T --)
		solve();

	return 0;
}