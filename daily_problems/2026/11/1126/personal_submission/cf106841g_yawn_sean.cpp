#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n, k;
	cin >> m >> n >> k;

	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;

	int W = 232792560;
	vector<vector<long long>> grid(n + 1, vector<long long>(m + 1, 0));

	while (k --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int w = W / (x2 - x1 + 1) / (y2 - y1 + 1);

		for (int x = x1; x <= x2; x ++) {
			for (int y = y1; y <= y2; y ++) {
				grid[x][y] += w;
			}
		}
	}

	for (int x = sx; x <= ex; x ++) {
		for (int y = sy; y <= ey; y ++) {
			if (x == sx && y == sy) continue;
			long long res = 1e18;
			if (x > sx) res = min(res, grid[x - 1][y]);
			if (y > sy) res = min(res, grid[x][y - 1]);
			grid[x][y] += res;
		}
	}

	int mod = 1e9 + 7;
	cout << grid[ex][ey] % mod * quickPow(W, mod - 2, mod) % mod;

	return 0;
}