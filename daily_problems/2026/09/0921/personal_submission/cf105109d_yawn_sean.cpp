#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

typedef __int128 lll;

const int MAXN = 51;
static lll tmp[MAXN][MAXN];

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

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, mod = 1e9 + 7;
	long long k;
	cin >> n >> k;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	vector<vector<int>> grid(n, vector<int>(n, 0));
	grid[0] = nums;

	for (int i = 1; i < n; i ++) grid[i][i - 1] = 1;

	if (k <= n) cout << nums[k - 1];
	else {
		auto res = matrix_pow(grid, k - n, mod - 1)[0];
		int ans = 1;

		for (int i = 0; i < n; i ++)
			ans = 1ll * ans * quickPow(nums[i], res[n - 1 - i], mod) % mod;

		cout << ans;
	}

	return 0;
}