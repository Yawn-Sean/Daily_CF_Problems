#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k, mod = 1e9 + 7;
	cin >> k;

	vector<int> v1(k), v2(k);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	vector<vector<int>> xn(2 * k, vector<int>(k, 0));

	for (int i = 0; i < k; i ++) xn[i][i] = 1;

	for (int i = k; i < 2 * k; i ++) {
		for (int j = 0; j < k; j ++) {
			for (int x = 0; x < k; x ++) {
				xn[i][x] = (xn[i][x] + 1ll * xn[i - j - 1][x] * v1[j]) % mod;
			}
		}
	}

	auto solve = [&] (auto &self, int x) -> vector<int> {
		if (x < 2 * k) return xn[x];

		auto v = self(self, x / 2);
		int tag = x % 2;

		vector<int> res(2 * k, 0);

		for (int i = 0; i < k; i ++) {
			for (int j = 0; j < k; j ++) {
				res[i + j + tag] = (res[i + j + tag] + 1ll * v[i] * v[j]) % mod;
			}
		}

		vector<int> ans(k, 0);

		for (int i = 0; i < 2 * k; i ++) {
			for (int j = 0; j < k; j ++) {
				ans[j] = (ans[j] + 1ll * res[i] * xn[i][j]) % mod;
			}
		}

		return ans;
	};

	vector<vector<int>> equations(k, vector<int>(k + 1));

	for (int i = 0; i < k; i ++) {
		auto tmp = solve(solve, v2[k - 1] - v2[i]);
		for (int j = 0; j < k; j ++) {
			equations[j][i] = tmp[j];
		}
	}

	{
		auto tmp = solve(solve, v2[k - 1]);
		for (int j = 0; j < k; j ++) {
			equations[j][k] = tmp[j];
		}
	}

	int pt = 0;

	for (int i = 0; i < k; i ++) {
		int chosen = -1;

		while (pt < k + 1 && chosen == -1) {
			for (int j = i; j < k; j ++) {
				if (equations[i][pt]) {
					chosen = j;
					break;
				}
			}
			pt ++;
		}

		pt --;

		if (chosen != i) swap(equations[i], equations[chosen]);
		if (pt == k + 1) break;

		int v = quickPow(equations[i][pt], mod - 2, mod);

		for (int j = pt; j <= k; j ++) {
			equations[i][j] = 1ll * equations[i][j] * v % mod;
		}

		for (int j = i + 1; j < k; j ++) {
			int w = (mod - equations[j][pt]) % mod;
			for (int x = pt; x <= k; x ++) {
				equations[j][x] = (equations[j][x] + 1ll * equations[i][x] * w) % mod;
			}
		}
	}

	for (int i = k - 1; i >= 0; i --) {
		for (int j = 0; j <= k; j ++) {
			if (equations[i][j]) {
				for (int x = 0; x < i; x ++) {
					int w = (mod - equations[x][j]) % mod;
					for (int y = j; y <= k; y ++) {
						equations[x][y] = (equations[x][y] + 1ll * equations[i][y] * w) % mod;
					}
				}
				break;
			}
		}
	}

	for (int i = 0; i < k; i ++) {
		cout << equations[i][k] << " \n"[i == k - 1];
	}

	return 0;
}