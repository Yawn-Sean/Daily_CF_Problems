#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
struct DSU {
	std::vector<int> f;
	std::vector<int> l, r;
	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		f.resize(n);
		l.resize(n);
		r.resize(n);
		std::iota(f.begin(), f.end(), 0);
		std::iota(l.begin(), l.end(), 0);
		std::iota(r.begin(), r.end(), 0);
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
		f[y] = x;
		l[x] = std::min(l[x], l[y]);
		r[x] = std::max(r[x], r[y]);
		return true;
	}
	std::pair<int, int> quan(int x) {
		return {l[find(x)], r[find(x)]};
	}
};
void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<DSU> d(n + 1, DSU(m + 2));
	std::vector vis(n + 1, std:: vector<int>(m + 2, 0));
	std::vector<int> vv(n + 10, 0);
	while (q--) {
		int x, y;
		if (q == 3) {
			q = q;
		}
		std::cin >> x >> y;

		auto  [x1, y1] = d[x].quan(y);
		if (vis[x][x1]) {
			x1--;
		}
		if (vis[x][y1]) {
			y1++;
		}
		if (y1 == m + 1) {
			y1 = 1e8;
		}
		if (x1 == 0) {
			x1 = -1e8;
		}
		int dx = std::min(y - x1, y1 - y);
		if (x1 == -1e8 && y1 == 1e8) {
			dx = n * m;
		}
		int ansx = 0, ansy = 0;
		if (y - x1 <= y1 - y) {
			ansx = x;
			ansy = x1;

		}
		else {
			ansx = x;
			ansy = y1;
		}
		for (int i = 1; i <= dx && x + i <= n; i++) {

			if (vv[x + i] == m) {
				continue;
			}
			auto [x1, y1] = d[x + i].quan(y);
			if (vis[x + i][x1]) {
				x1--;
			}
			if (vis[x + i][y1]) {
				y1++;
			}
			if (y1 == m + 1) {
				y1 = 1e8;
			}
			if (x1 == 0) {
				x1 = -1e8;
			}
			if (y1 == 1e8 && x1 == -1e8) {
				continue;
			}
			if (y - x1 <= y1 - y) {
				if (y - x1 + i < dx) {
					ansx = x + i;
					ansy = x1;
					dx = y - x1 + i;
				}
			}
			else {
				if (y1 - y + i < dx) {
					ansx = x + i;
					ansy = y1;
					dx = y1 - y + i;
				}
			}
		}
		for (int i = 1; i <= dx && x - i >= 1; i++) {
			if (vv[x - i] == m) {
				continue;
			}
			auto [x1, y1] = d[x - i].quan(y);
			if (vis[x - i][x1]) {
				x1--;
			}
			if (vis[x - i][y1]) {
				y1++;
			}
			if (y1 == m + 1) {
				y1 = 1e8;
			}
			if (x1 == 0) {
				x1 = -1e8;
			}
			if (y1 == 1e8 && x1 == -1e8) {
				continue;
			}
			if (y - x1 <= y1 - y) {
				if (y - x1 + i <= dx) {
					ansx = x - i;
					ansy = x1;
					dx = y - x1 + i;
				}
			}
			else {
				if (y1 - y + i <= dx) {
					ansx = x - i;
					ansy = y1;
					dx = y1 - y + i;
				}
			}
		}

		std::cout << ansx << " " << ansy << endl;
		vis[ansx][ansy] = 1;
		vv[ansx]++;
		if (vis[ansx][ansy + 1])
			d[ansx].merge(ansy, ansy + 1);
		if (vis[ansx][ansy - 1])
			d[ansx].merge(ansy, ansy - 1);

	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
