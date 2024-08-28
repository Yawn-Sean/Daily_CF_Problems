#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

void solve() {
	int n;
	std::cin >> n;
	
	int m = n * 2;

	std::vector<int> a(m);
	std::map<int, int> pre, suf;

	for (int i = 0; i < m; ++ i) std::cin >> a[i];

	for (int i = 0, f = 0; i < n; ++ i) {
		f += (a[i] & 1 ? 1 : -1);
		pre[f] = i;
	}

	int res = m;

	for (int i = m - 1, f = 0; i >= n; -- i) {
		f += (a[i] & 1 ? -1 : 1);
		if (pre.contains(f)) {
			res = std::min(res, i - pre[f] - 1);
		}
		if (f == 0)
			res = std::min(res, i);
	}

	if (pre.contains(0))
		res = std::min(res, m - pre[0] - 1);

	std::cout << res << '\n';
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
	std::cin >> T;
	while (T --) {
		solve();
	}

	return 0;
}