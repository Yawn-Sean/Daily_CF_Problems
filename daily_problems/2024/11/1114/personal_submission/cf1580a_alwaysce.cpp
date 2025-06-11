#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> grid(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				grid[i][j] = (c - '0');
			}
		}
		
		int ans = n * m;
		vector<int> cnt(m), calc(m);
		
		// 枚举上边
		for (int i = 0; i < n - 4; i++) {
			// 初始化
			for (int j = 0; j < m; j++) {
				cnt[j] = 0;
			}
			
			// 作为内部行的操作次数
			// cnt[k]: 第k列作为边上的列需要操作几次
			for (int j = i + 1; j < i + 4; j++) {
				for (int k = 0; k < m; k++) {
					cnt[k] += grid[j][k]; // 包含了边上
				}
			}
			
			// 枚举下边
			for (int j = i + 4; j < n; j++) {
				for (int k = 0; k < m; k++) {
					calc[k] = cnt[k];
				}
				
				// calc[k]: 作为内部列k需要的次数
				for (int k = 1; k < m; k++) {
					calc[k] = (calc[k] + 2 - grid[i][k] - grid[j][k]);
				}
				
				// :k]列的累计操作次数(前缀和)
				for (int k = 1; k < m; k++) {
					calc[k] += calc[k - 1];
				}
				
				// k: 右侧边界
				int cur = n * m;
				// 第一个数组到右边界（左侧一列）的前缀和 + 右边界调整次数
				for (int k = m - 1; k >= 3; k--) {
					// 后缀最小值=cur - 前面至少3列的左边的总调整次数
					cur = min(cur, calc[k - 1] + (j - i - 1) - cnt[k]); // 右边界操作次数=(j-i-1)-cnt[k]
					ans = min(ans, cur - calc[k - 3] + (j - i - 1) - cnt[k - 3]);
					
				}
				
				for (int k = 0; k < m; k++) {
					cnt[k] += grid[j][k];
				}
			}
			
		}
		cout << ans << '\n';
	}
    return 0;
}
