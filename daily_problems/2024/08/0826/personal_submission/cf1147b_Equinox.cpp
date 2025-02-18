#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

/*
	旋转 k 可行，则旋转 kx 也可行
	旋转 kx mod n 也可行

	ax + bn = gcd(x ,n)
*/

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::set<std::pair<int, int>> st;
	std::vector<std::pair<int, int>> segs(m);

	for (int i = 0, a, b; i < m; ++ i) {
		std::cin >> a >> b;
		-- a, -- b;
		if (a > b) std::swap(a, b);
		st.emplace(a, b);
		segs[i] = { a, b };
	}

	for (int i = 2, t = n; i <= n && t > 1; ++ i) {
		if (t % i == 0) {
			while (t % i == 0) t /= i;
			int x = n / i;
			bool ok = true;
			for (int j = 0; j < m; ++ j) {
				auto [l, r] = segs[j];
				int nl = (l + x) % n, nr = (r + x) % n;
				if (nl > nr) std::swap(nl, nr);
				if (!st.contains(std::pair(nl, nr))) {
					ok = false;
					break;
				}
			}
			if (ok) {
				std::cout << "Yes";
				return;
			}
		}
	}

	std::cout << "No";
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