#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1'000'000'007;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n << 1);

	for (int i = 1, j = 0; i < n; i += 2, ++ j) 
		a[j] = a[j + n - i] = i;
	for (int i = 2, j = n; i < n; i += 2, ++ j) 
		a[j] = a[j + n - i] = i;
	for (int i = 0; i < n * 2; ++ i) 
		if (!a[i])
			a[i] = n;
	for (int x : a) std::cout << x << ' ';
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