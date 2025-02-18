#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1E9 + 7;

void solve(){
	int n, k;

	std::cin >> n >> k;

	std::vector<int> a(n), cnt(16384);
	for (int i = 0; i < n; ++ i)
		std::cin >> a[i], ++ cnt[a[i]];

	i64 res = 0;

	if (k == 0) {
		for (int x : cnt)
			res += 1LL * x * (x - 1) / 2;
		std::cout << res << '\n';
		return;
	}

	std::vector<int> b;

	int msk = 1 << 14, cur = (1 << k) - 1;
	while (cur < msk) {
		b.push_back(cur);
		int lb = cur & -cur;
		int left = cur + lb;
		int right = (left ^ cur) >> (__builtin_ctz(lb) + 2);
		cur = left | right;		
	}

	for (int i = n - 1; ~i; -- i) {
		for (int x : b)
			res += cnt[a[i] ^ x];
		-- cnt[a[i]];
	}

	std::cout << res;
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