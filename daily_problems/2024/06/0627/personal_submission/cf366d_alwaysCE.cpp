#include <bits/stdc++.h>
using i64 = long long;

i64 inf = 100000007;
i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
		
	int n, m;
	std::cin >> n >> m;
	
	DSU u(n);

	std::vector<int> a(m), b(m), ls(m), rs(m);
	std::vector<int> tl(m), tr(m);
	
	for (int i = 0; i < m; i++) {
		std::cin >> a[i] >> b[i] >> ls[i] >> rs[i];
		a[i]--; b[i]--;
		tl[i] = ls[i]; tr[i] = rs[i];
	}
	
	std::sort(tl.begin(), tl.end());
	std::sort(tr.begin(), tr.end());
	
	// unique: 返回"去重之后"vector的末尾地址
	auto l1 = std::unique(tl.begin(), tl.end());
	auto r1 = std::unique(tr.begin(), tr.end());
	int ans = 0;
	auto pl = tl.begin(), pr = tr.begin();
	
	std::function<bool(void)> check = [&]() -> bool{
		u.init(n);
		for (int i = 0; i < m; i++) {
			if (ls[i] <= *pl and *pr <= rs[i]) {
				u.merge(a[i], b[i]);
			}
		}
		return u.same(0, n - 1);
	};
	
	while (pl != l1) {
		while (pr != r1 and check()) {
			pr++;
		}
		// 当前pr刚好不满足, 上一个位置满足需求
		if (pr != tr.begin()) {
			ans = std::max(ans, *(pr - 1) - *pl + 1);
		}
		pl++;
	}
	
	if (ans > 0) {
		std::cout << ans << '\n';
	} else {
		std::cout << "Nice work, Dima!" << '\n';
	}
	return 0;
}
