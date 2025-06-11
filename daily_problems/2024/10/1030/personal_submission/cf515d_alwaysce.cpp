#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		从只有1个方向能放的空格子开始dfs
	*/
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	
	vector<vector<int>> cnt(n, vector<int>(m, 0));
	vector<int> dx = {-1, 0, 1, 0};
	vector<int> dy = {0, 1, 0, -1};
	vector<string> ss = {"v^", "<>", "^v", "><"};
	
	auto ok = [&](int i, int j) {
		return (i >= 0 and i < n) and (j >= 0 and j < m) and grid[i][j] == '.';	
	};
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					if (ok(i + dx[k], j + dy[k])) {
						cnt[i][j]++;
					}
				}
			}
		}
	}

	
 	function<void(int,int)> dfs = [&](int i, int j) {
		for (int d = 0; d < 4; d++) {
			int ni = i + dx[d];
			int nj = j + dy[d];
			if (ok(ni, nj)) {
				cnt[i][j] = 0;
				cnt[ni][nj] = 0;
				
				grid[i][j] = ss[d][0];
				grid[ni][nj] = ss[d][1];
				
				for (int nd = 0; nd < 4; nd++) {
					int tmp_i = ni + dx[nd];
					int tmp_j = nj + dy[nd];
					if (ok(tmp_i, tmp_j)) {
						cnt[tmp_i][tmp_j]--;
						if (cnt[tmp_i][tmp_j] == 1) {
							dfs(tmp_i, tmp_j);
						}	
					}
				}
			}
		}
	};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnt[i][j] == 1) {
				dfs(i, j);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.') {
				cout << "Not unique\n";
				return 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
    return 0;
}
