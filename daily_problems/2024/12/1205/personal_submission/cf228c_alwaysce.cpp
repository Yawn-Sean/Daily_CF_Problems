#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;


int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n, vector<int>(m));	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			grid[i][j] = (c == '*'); 
		}
	}
	
	/*
		Note: 涂黑的方块可以是1-4块的其中任意1-3个 除了不能是全部
	*/
	vector<vector<int>> dp(n, vector<int>(m, -1)), ndp(n, vector<int>(m, -1));
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			dp[i][j] = 0;
			for (int di = 0; di < 2; di++) {
				for (int dj = 0; dj < 2; dj++) {
					dp[i][j] = 2*dp[i][j] + (grid[i+di][j+dj]); // 按照黑色编码
					// 1111
				}
			}

		}
	}
	
	int ans = 0;
	for (int k = 1; k < 8; k++) {
		int L = (1 << k);
		for (int i = 0; i + 2 * L <= n; i++) {
			for (int j = 0; j + 2 * L <= m; j++) {
				int msk = 0;
				
				for (int di = 0; di < 2; di++) {
					for (int dj = 0; dj < 2; dj++) {
						msk = 2*msk + (dp[i+di*L][j+dj*L] == 15); // 寻找全黑位置
					}
				}
				
				bool find = true;
				for (int di = 0; di < 2; di++) {
					for (int dj = 0; dj < 2; dj++) {
						if (dp[i+di*L][j+dj*L] != 15 and dp[i+di*L][j+dj*L] != msk) {
							// 包含白色区域的黑色顺序对应不上
							find = false;
						}
					}
				}
				if (find) { ndp[i][j] = msk; }
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = ndp[i][j];
				ndp[i][j] = -1;
				if (dp[i][j] != -1) {
					ans++;
				}
			}
		}
		
	}
	
	cout << ans;
	return 0;
}
