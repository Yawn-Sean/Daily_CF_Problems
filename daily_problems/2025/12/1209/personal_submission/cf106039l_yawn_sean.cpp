#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

vector<vector<long long>> matrix_mul(vector<vector<long long>> grid1, vector<vector<long long>> grid2, long long mod) {
    int n = grid1.size(), m = grid1[0].size(), x = grid2[0].size();
    vector<vector<long long>> ans(n, vector<long long>(x));
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < m; j ++)
            for (int k = 0; k < x; k ++)
                ans[i][k] += grid1[i][j] * grid2[j][k], ans[i][k] %= mod;
    return ans;
}

vector<vector<long long>> matrix_pow(vector<vector<long long>> grid, long long power, long long mod) {
    if (power == 1)
        return grid;
    int n = grid.size();
    if (power == 0) {
        vector<vector<long long>> ans(n, vector<long long>(n));
        for (int i = 0; i < n; i ++)
            ans[i][i] = 1;
        return ans;
    }
    vector<vector<long long>> ans = matrix_pow(grid, power / 2, mod);
    if (power & 1)
        return matrix_mul(matrix_mul(ans, ans, mod), grid, mod);
    return matrix_mul(ans, ans, mod);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<string> grid(n);
	for (auto &s: grid) cin >> s;

	auto f = [&] (int i, int j) -> int {return i * n + j;};

	vector<vector<long long>> transition(n * n, vector<long long>(n * n, 0));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (grid[i][j] != '#') {
				for (int di = -1; di <= 1; di ++) {
					for (int dj = -1; dj <= 1; dj ++) {
						int ni = i + di, nj = j + dj;
						if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != '#') {
							transition[f(i, j)][f(ni, nj)] = 1;
						}
					}
				}
			}
		}
	}

	auto kth_transition = matrix_pow(transition, k, 2);
	vector<vector<int>> ans(n, vector<int>(n, 0));

	for (int i1 = 0; i1 < n; i1 ++) {
		for (int j1 = 0; j1 < n; j1 ++) {
			for (int i2 = 0; i2 < n; i2 ++) {
				for (int j2 = 0; j2 < n; j2 ++) {
					if (kth_transition[f(i1, j1)][f(i2, j2)]) {
						ans[i2][j2] ^= grid[i1][j1] - '0';
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (grid[i][j] == '#') cout << '#';
			else cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}