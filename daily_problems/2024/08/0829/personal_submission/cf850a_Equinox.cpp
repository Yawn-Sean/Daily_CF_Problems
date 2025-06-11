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

	if (n >= 34) {
		std::cout << 0;
		return;
	}

	std::vector<std::vector<int>> v(5);

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < 5; ++ j) {
			v[j].emplace_back();
			std::cin >> v[j].back();
		}
	}

	std::vector<int> ans;

	for (int i = 0; i < n; ++ i) {
		bool f = true;
		for (int j = 0; f && j < n; ++ j) {
			for (int k = 0; f && k < j; ++ k) {
				int dot = 0;
				for (int x = 0; x < 5; ++ x)
					dot += (v[x][j] - v[x][i]) * (v[x][k] - v[x][i]);
				if (dot > 0) 
					f = false;
			}
		}
		if (f)
			ans.push_back(i);
	}

	std::cout << ans.size() << '\n';

	for (int x : ans) std::cout << x + 1 << '\n';
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