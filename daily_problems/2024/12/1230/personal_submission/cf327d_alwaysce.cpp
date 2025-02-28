#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if (ch == '#') {
				mat[i][j] = 1;
			} else {
				mat[i][j] = 0;
			}
		}
	}
	vector<int> dx{1, 0, -1, 0};
	vector<int> dy{0, 1, 0, -1};
	
	vector<pair<int,int>> ans;
	function<void(int,int,bool)> dfs = [&](int i, int j, bool is_first) {
		ans.emplace_back(0, i * m + j);
		mat[i][j] = 1;
		for (int k = 0; k < 4; k++) {
			int ni = i + dx[k], nj = j + dy[k];
			if (ni >= 0 and ni < n and nj >= 0 and nj < m and mat[ni][nj] == 0) {
				dfs(ni, nj, false);
			}
		}
		if (!is_first) {
			ans.emplace_back(2, i * m + j);
			ans.emplace_back(1, i * m + j);
		}
	};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0) {
				dfs(i, j, true);
			}
		}
	}
	
	cout << ans.size() << '\n';
	vector<char> choice{'B', 'R', 'D'};
	for (auto& pr: ans) {
		int x = pr.second / m, y = pr.second % m;
		cout << choice[pr.first] << ' ' << x + 1 << ' ' << y + 1 << '\n';
	}	
	return 0;
}
