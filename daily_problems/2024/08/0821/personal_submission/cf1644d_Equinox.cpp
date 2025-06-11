#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

constexpr int N = 200'005, M = 200'005;
int r[N], c[N];
int opx[N], opy[N];

void solve() {
	int n, m, k, q;
	std::cin >> n >> m >> k >> q;

	for (int i = 0, x, y; i < q; ++ i) {
		std::cin >> opx[i] >> opy[i];
		-- opx[i], -- opy[i];
	}

	int resr = n, resc = m;
	int ans = 1;

	for (int i = q - 1; ~i; -- i) {
		int x = opx[i], y = opy[i];
		if ((!r[x] && resc) || (!c[y] && resr)) {
			ans = 1LL * ans * k % P;
		
			if (!r[x]) r[x] = 1, -- resr;
			if (!c[y]) c[y] = 1, -- resc;
		}
	}

	for (int i = 0; i < q; ++ i) {
		int x = opx[i], y = opy[i];
		r[x] = c[y] = 0;
	}

	std::cout << ans << '\n';
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
	while (T --)
		solve();

	return 0;
}