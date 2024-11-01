#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
	总共有 n 人在散步，他们立刻决定过河。
	我们知道，这条船最多可以载重 k 千克的人。
	每个人的体重要么是 50 千克，要么是 100 千克。
	现在格雷格想知道，要把整个小组的人运到对岸，小船至少要过河多少次。
	小船至少需要一个人驾驶才能从河岸到达对岸。
	小船过河时，只要乘客的总重量不超过 k ，乘客的人数不为零。

	格雷格还想知道，有多少种方法可以在最少的乘船次数内将所有人运送到对岸。
	如果在某次乘船过程中，船上有不同的两组人，那么这两种方式就被认为是不同的。
	*/
	
	vector<vector<i64>> comb(51, vector<i64>(51, 0));
	for (int i = 0; i <= 50; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i - 1][j] % mod + comb[i - 1][j - 1] % mod) % mod;
		}
	}
	int n, k;
	cin >> n >> k;
	k /= 50;
	
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 50) {
			++c1;
		} else {
			++c2;
		}
	}
	
	// dp[i][j]: 右岸有i个50重量 j个100重量的方案数量
	vector<vector<i64>> dp(c1 + 1, vector<i64>(c2 + 1, 0));
	vector<vector<i64>> ndp(c1 + 1, vector<i64>(c2 + 1, 0));
	vector<vector<i64>> vis(c1 + 1, vector<i64>(c2 + 1, 0));
	vector<vector<i64>> nvis(c1 + 1, vector<i64>(c2 + 1, 0));
	dp[0][0] = 1;
	vis[0][0] = 1;
	
	// Round i
	for (int i = 0; i <= 2 * n; i++) {
		// L -> R
		for (int x = 0; x <= c1; x++) {
			for (int y = 0; y <= c2; y++) {
				if (!vis[x][y]) continue;
				
				for (int nx = 0; x + nx <= c1; nx++) {
					for (int ny = 0; y + ny <= c2; ny++) {
						if (nx + 2 * ny <= k) {
							ndp[x + nx][y + ny] += 1ll * dp[x][y] * comb[c1 - x][nx] % mod * comb[c2 - y][ny] % mod;
							nvis[x + nx][y + ny] = 1;
							if (ndp[x + nx][y + ny] >= mod) {
								ndp[x + nx][y + ny] -= mod;
							}
						}
					}
				}
			}
		}
		
		for (int x = 0; x <= c1; x++) {
			for (int y = 0; y <= c2; y++) {
				dp[x][y] = ndp[x][y];
				vis[x][y] = nvis[x][y];
				ndp[x][y] = 0;
				nvis[x][y] = 0;
			}
		}
		
		if (vis[c1][c2]) {
			cout << 2 * i + 1 << '\n';
			cout << dp[c1][c2];
			return 0;
		}
		
		// R -> L
		for (int x = 0; x <= c1; x++) {
			for (int y = 0; y <= c2; y++) {
				if (!vis[x][y]) continue;
				
				for (int nx = 0; nx <= x; nx++) {
					for (int ny = 0; ny <= y; ny++) {
						if ((nx > 0 or ny > 0) and nx + 2 * ny <= k) {
							ndp[x - nx][y - ny] += 1ll * dp[x][y] * comb[x][nx] % mod * comb[y][ny] % mod;
							nvis[x - nx][y - ny] = 1;
							if (ndp[x - nx][y - ny] >= mod) {
								ndp[x - nx][y - ny] -= mod;
							}
						}
					}
				}
			}
		}
		
		for (int x = 0; x <= c1; x++) {
			for (int y = 0; y <= c2; y++) {
				dp[x][y] = ndp[x][y];
				vis[x][y] = nvis[x][y];
				ndp[x][y] = 0;
				nvis[x][y] = 0;
			}
		}
	}
	
	cout << -1 << '\n' << 0;
    return 0;
}
