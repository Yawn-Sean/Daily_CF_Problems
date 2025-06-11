#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

int query(int x) {
	std::cout << "? " << x << std::endl;

	int res;
	std::cin >> res;
	
	return res;
}

void solve() {
	int n;
	std::cin >> n;

	if (n & 2) {
		std::cout << "! -1" << std::endl;
		return;
	}

	int l = query(1), r = query(1 + n / 2);

	int f = l == r ? 0 : (l < r ? 1 : -1);
	if (f == 0) {
		std::cout << "! " << 1 << std::endl;
		return;
	}

	int lo = 1, hi = n / 2 + 1;

	while (lo < hi) {
		int x = lo + hi >> 1;
		l = query(x), r = query(x + n / 2);
		int nf = l == r ? 0 : (l < r ? 1 : -1);

		if (nf == 0) {
			std::cout << "! " << x << std::endl;
			return;
		}

		if (nf == f)
			lo = x + 1;
		else
			hi = x;
	}

	std::cout << "! " << -1 << std::endl;
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
	while (T --) {
		solve();
	}

	return 0;
}