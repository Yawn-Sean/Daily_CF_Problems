#include <bits/stdc++.h>
#include <ranges>

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

	std::vector<int> a(n);

	for (int i = 0; i < n; ++ i) std::cin >> a[i];

	int L = 0, R = 0;
	
	for (int i = 0; i < n; ++ i)
		if (!i || a[i] > a[i - 1])
			++ L;
		else
			break;

	for (int i = n - 1; ~i; -- i)
		if (i + 1 == n || a[i] > a[i + 1])
			++ R;
		else
			break;

	if (((L + R) & 1) || ((L & 1) && (R & 1)))
		std::cout << "Alice";
	else
		std::cout << "Bob";
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