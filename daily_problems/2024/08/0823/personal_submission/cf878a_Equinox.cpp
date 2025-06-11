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

	std::vector<int> a(10, 2);

	for (int i = 0; i < n; ++ i) {
		char op;
		int x;
		std::cin >> op >> x;

		for (int b = 0; b < 10; ++ b) {
			if (op == '&' && !(x >> b & 1)) {
				a[b] = 0;
			}
			if(op == '|' && (x >> b & 1)) {
				a[b] = 1;
			}
			if (op == '^' && (x >> b & 1)){
				a[b] ^= 1;
			}
		}
	}

	std::vector<int> ans(3);

	for (int i = 0; i < 10; ++ i)
		if (a[i] == 0)
			ans[0] |= 1 << i;
		else if(a[i] == 1)
			ans[1] |= 1 << i;
		else if(a[i] == 3)
			ans[2] |= 1 << i;

	std::cout << "3\n";

	std::cout << "& " << (1023 ^ ans[0]) << '\n';
	std::cout << "| " << ans[1] << '\n';
	std::cout << "^ " << ans[2] << '\n';
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
	// std::cin >> T;s
	while (T --)
		solve();

	return 0;
}