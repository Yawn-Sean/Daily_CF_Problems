#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve(){
	int n, k;
	std::cin >> n >> k;

	if (k % 2 == 0) {
		std::cout << -1;
		return;
	}

	std::vector<int> a(n);
	std::iota(a.begin(), a.end(), 1);

	// [l, r)
	auto dfs = [&](auto &&self, int l, int r) -> void {
        if (k == 0 || l + 1 == r) return;
        int m = (l + r) / 2;
        k -= 2;
        std::swap(a[m - 1], a[m]);
        self(self, l, m);
        self(self, m, r);
	};

	-- k;
	dfs(dfs, 0, n);

	if (k)	std::cout << -1;
	else	for (int x : a) std::cout << x << ' ';
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