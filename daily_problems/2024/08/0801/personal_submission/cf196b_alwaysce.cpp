#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::string> grid(n);
	for (int i = 0; i < n; i++) {
		std::cin >> grid[i];
	}
	
	int sx, sy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}
	
	int inf = 1E9;
	
	std::vector<std::vector<std::pair<int,int> > > vis(n, std::vector<std::pair<int,int>>(m, {inf, inf} ) );;
	std::vector<int> dx{1, 0, -1, 0};
	std::vector<int> dy{0, 1, 0, -1};
	
	bool find = false;
	std::function<bool(int,int)> dfs = [&](int x, int y) -> bool{
		if (find) {
			return true;
		}
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			int px = (nx % n + n) % n, py = (ny % m + m) % m;
			if (grid[px][py] == '#') continue;
			
			if (vis[px][py].first == inf) {
				vis[px][py] = {nx, ny};
				if (dfs(nx, ny)) {
					return true;
				}
			} else if (vis[px][py].first != nx or vis[px][py].second != ny) {
				find = true;
				return true;
			}
		}
		return false;
	};
	
	vis[sx][sy] = {sx, sy};
	dfs(sx, sy);
	
	std::cout << (find ? "Yes" : "No") << '\n';
	return 0;
}
