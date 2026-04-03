#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	x --, y --;

	int k = 1 << n;

	vector<string> ans(k, string(k, '.'));
	ans[x][y] = '#';

	auto f = [&] (auto &self, int lx, int rx, int ly, int ry, int x, int y) -> void {
		if (lx + 2 == rx) {
			char c = 'B' + (lx / 2 + ly / 2) % 2;
			for (int i = lx; i < rx; i ++) {
				for (int j = ly; j < ry; j ++) {
					if (ans[i][j] == '.') {
						ans[i][j] = c;
					}
				}
			}
			return ;
		}

		int mx = (lx + rx) / 2, my = (ly + ry) / 2;

		if (x < mx) {
			if (y < my) {
				ans[mx - 1][my] = 'A';
				ans[mx][my - 1] = 'A';
				ans[mx][my] = 'A';
				self(self, lx, mx, ly, my, x, y);
				self(self, lx, mx, my, ry, mx - 1, my);
				self(self, mx, rx, ly, my, mx, my - 1);
				self(self, mx, rx, my, ry, mx, my);
			}
			else {
				ans[mx - 1][my - 1] = 'A';
				ans[mx][my - 1] = 'A';
				ans[mx][my] = 'A';
				self(self, lx, mx, ly, my, mx - 1, my - 1);
				self(self, lx, mx, my, ry, x, y);
				self(self, mx, rx, ly, my, mx, my - 1);
				self(self, mx, rx, my, ry, mx, my);
			}
		}
		else {
			if (y < my) {
				ans[mx - 1][my - 1] = 'A';
				ans[mx - 1][my] = 'A';
				ans[mx][my] = 'A';
				self(self, lx, mx, ly, my, mx - 1, my - 1);
				self(self, lx, mx, my, ry, mx - 1, my);
				self(self, mx, rx, ly, my, x, y);
				self(self, mx, rx, my, ry, mx, my);
			}
			else {
				ans[mx - 1][my - 1] = 'A';
				ans[mx - 1][my] = 'A';
				ans[mx][my - 1] = 'A';
				self(self, lx, mx, ly, my, mx - 1, my - 1);
				self(self, lx, mx, my, ry, mx - 1, my);
				self(self, mx, rx, ly, my, mx, my - 1);
				self(self, mx, rx, my, ry, x, y);
			}
		}
	};

	f(f, 0, k, 0, k, x, y);

	cout << "YES\n";
	for (auto &x: ans) cout << x << '\n';

	return 0;
}