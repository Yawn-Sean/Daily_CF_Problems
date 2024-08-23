#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; ++ i)
		std::cin >> a[i];
	
	std::vector<int> f(n, 1);
	
	auto check = [&](int x) -> bool {
		f.assign(n, 1);	

		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < i; ++ j) {
				if (abs(a[i] - a[j]) <= 1LL * (i - j) * x)
					f[i] = std::max(f[i], f[j] + 1);
			}
		}

		return *std::max_element(f.begin(), f.end()) >= n - k;
	};
	
	int lo = 0, hi = 2E9 + 1;

	while (lo < hi) {
		int x = lo + (hi - lo) / 2;
		if (check(x))
			hi = x;
		else 
			lo = x + 1;
	}

	std::cout << hi;
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