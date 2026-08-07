#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

typedef __int128 lll;

const int MAXN = 5;
static lll tmp[MAXN][MAXN];

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

vector<vector<int>> matrix_mul(const vector<vector<int>>& A,
								const vector<vector<int>>& B, int mod) {
	int n = A.size(), m = A[0].size(), x = B[0].size();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < x; j++)
			tmp[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			lll aik = A[i][k];
			for (int j = 0; j < x; j++)
				tmp[i][j] += aik * B[k][j];
		}
	}

	vector<vector<int>> ans(n, vector<int>(x));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < x; j++)
			ans[i][j] = (int)(tmp[i][j] % mod);
	return ans;
}

vector<vector<int>> matrix_pow(vector<vector<int>> grid, long long power, int mod) {
	int n = grid.size();
	vector<vector<int>> ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) ans[i][i] = 1;
	while (power > 0) {
		if (power & 1) ans = matrix_mul(ans, grid, mod);
		grid = matrix_mul(grid, grid, mod);
		power >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		long long n;
		cin >> n;

		int p0, q0, p1, q1, p2, q2;
		cin >> p0 >> q0 >> p1 >> q1 >> p2 >> q2;
		
		int x0 = p0 * quickPow(q0, mod - 2, mod) % mod;
		int y0 = (mod + 1 - x0) % mod;

		int x1 = p1 * quickPow(q1, mod - 2, mod) % mod;
		int y1 = (mod + 1 - x1) % mod;

		int x2 = p2 * quickPow(q2, mod - 2, mod) % mod;
		int y2 = (mod + 1 - x2) % mod;

		vector<vector<int>> grid = {
			{x1, x2, 0},
			{y1, y2, 0},
			{x1, x2, 1}
		};

		auto res = matrix_pow(grid, n - 1, mod)[2];

		int ans = 0;
		ans = (ans + 1ll * res[0] * x0) % mod;
		ans = (ans + 1ll * res[1] * y0) % mod;
		ans = (ans + 1ll * res[2] * x0) % mod;

		cout << ans << '\n';
	}

	return 0;
}