#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
/**   并查集（DSU）
 *    2023-08-04: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63239142
**/
struct DSU {
	std::vector<int> f, siz;

	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		f.resize(n);
		std::iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}

	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		if (siz[x] < siz[y]) {
			std::swap(x, y);
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
};
void solve() {
	i64 n, m, g, s;
	std::cin >> n >> m >> g >> s;
	std::vector<std::array<i64, 4>> e(m);
	for (int i = 0; i < m; i++) {
		std::cin >> e[i][0] >> e[i][1] >> e[i][2] >> e[i][3];
		e[i][0]--;
		e[i][1]--;
	}
	std::sort(e.begin(), e.end(), [&](auto & a1, auto & a2) {
		return a1[2] < a2[2];
	});
	i64 ans = 4e18;
	std::vector<std::array<i64, 3>> st;
	for (int i = 0; i < m; i++) {
		st.push_back({e[i][3], e[i][0], e[i][1]});
		DSU d(n);
		for (int j = st.size() - 1; j > 0; j--) {
			if (st[j][0] < st[j - 1][0]) {
				std::swap(st[j], st[j - 1]);
			}
		}
		int flag = 0;
		std::vector<std::array<i64, 3>> next;
		for (auto j = st.begin(); j != st.end(); j++) {
			auto &[x, u, v] = *j;
			if (d.merge(u, v)) {
				next.push_back(*j);
			}
			if (d.siz[d.find(0)] == n) {
				ans = std::min(ans, x * s + e[i][2] * g);
				break;
			}
		}
		st = std::move(next);
	}

	if (ans == 4e18) {
		ans = -1;
	}
	std::cout << ans << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
