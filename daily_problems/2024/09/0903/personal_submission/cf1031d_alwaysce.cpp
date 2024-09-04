#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	// 1. 去掉前缀的a
	// 2. 去掉之后开始bfs 跳过k个任意字符
	// 3. bfs 每一轮找最小的字符开头
	// 4. 记录每一次的min值
	
	vector<vector<char>> grid(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	
	vector<vector<int>> dp(n, vector<int>(n, 2*n));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch = grid[i][j];
			if (i > 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if (j > 0) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);	
			}
			dp[i][j] += (ch != 'a');
		}
	}
	
	int cur = 0;
	vector<pair<int,int>> tmp = {{0, 0}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] <= k) {
				if (i + j > cur) {
					cur = i + j;
					tmp.clear();
					tmp.push_back({i, j});
				} else if (i + j == cur) {
					tmp.push_back({i, j});
				}
			}
		}
	}
    
    cout << string(cur, 'a');
    auto [x, y] = tmp[0];
    cout << (dp[x][y] <= k ? 'a' : grid[x][y]);
    
    vector<pair<int,int>> dirs = {{0, 1}, {1, 0}};
    
    for (int i = cur + 1; i < 2 * n - 1; i++) {
    	vector<pair<int,int>> ntmp;
    	char nc = 'z' + 1;
    	for (auto& [x, y]: tmp) {
    		for (auto& [dx, dy]: dirs) {
    			if (x + dx < n and y + dy < n) {
    				if (grid[x + dx][y + dy] < nc) {
    					nc = grid[x + dx][y + dy];
    					ntmp.clear();
    					ntmp.push_back({x + dx, y + dy});
    				} else if (grid[x + dx][y + dy] == nc and ntmp.back().first != x + dx) {
    					// ntmp.back().first != x + dx去重
    					ntmp.push_back({x + dx, y + dy});
    				}
    			}
    		}
    	}
    	cout << nc;
    	tmp = ntmp;
    }
    return 0;
    
}
