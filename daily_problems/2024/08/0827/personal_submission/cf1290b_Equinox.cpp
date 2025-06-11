#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

void solve() {
	std::string s;
	std::cin >> s;

	int n = s.size();

	std::vector<std::array<int, 26>> acc(n + 1);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < 26; ++ j)
			acc[i + 1][j] = acc[i][j] + (s[i] == 'a' + j);
	}

	int q;
	std::cin >> q;

	for (int i = 0, l, r; i < q; ++ i) {
		std::cin >> l >> r;
		if (l == r) {
			std::cout << "Yes\n";
			continue;
		}
		int c = 0;
		for (int j = 0; j < 26; ++ j)
			c += (acc[r][j] - acc[l - 1][j] > 0);
		if (c > 2) {
			std::cout << "Yes\n";
			continue;		
		}
		if (c == 2 && s[l - 1] != s[r - 1]) {
			std::cout << "Yes\n";
			continue;			
		}
		std::cout << "No\n";
	}
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