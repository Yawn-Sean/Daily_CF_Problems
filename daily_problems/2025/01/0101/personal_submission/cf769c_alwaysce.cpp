#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	int si, sj;
	vector<int> dx{1, 0, 0, -1};
	vector<int> dy{0, -1, 1, 0};
	
	vector<vector<char>> maze(n, vector<char>(m, ' '));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'X') {
				si = i;
				sj = j;
			}
		}
	}

	
	if (k % 2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	vector<vector<int>> dis(n, vector<int>(m, inf));
	dis[si][sj] = 0;
	queue<pair<int,int>> q;
	q.push({si,sj});
	
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int i = cur.first, j = cur.second;
		for (int d = 0; d < 4; d++) {
			int ni = i + dx[d];
			int nj = j + dy[d];
			if (ni >= 0 and ni < n and nj >= 0 and nj < m and maze[ni][nj] == '.' and dis[ni][nj] == inf) {
				dis[ni][nj] = dis[i][j] + 1;
				q.push({ni, nj});
			}
		}
	}

	string ans;
	string ops = "DLRU";
	int x = si, y = sj;
	
	while (k > 0) {
		bool find = false;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 and nx < n and ny >= 0 and ny < m and maze[nx][ny] != '#') {
				if (dis[nx][ny] <= k - 1) {
					ans += ops[i];
					x = nx;
					y = ny;
					k -= 1;
					find = true;
					break;
				}
			}		
		}
		if (not find) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	cout << ans;
	
	return 0;
}
