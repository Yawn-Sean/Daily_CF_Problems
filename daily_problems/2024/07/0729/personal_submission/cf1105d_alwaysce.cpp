#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 998244353;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	int p;
	std::cin >> p;
	
	std::vector<int> speed(p + 1);
	for (int i = 1; i <= p; i++) {
		std::cin >> speed[i];
	}
	
	std::vector<std::vector<char>> grid(n, std::vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> grid[i][j];
		}
	}
	
	auto f = [&](int x, int y) {
		return x * m + y;
	};
	
	
	std::vector<std::vector<int>> cur(p + 1);
	std::vector<int> cnt(p + 1);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] >= '1' and grid[i][j] <= '9') {
				cur[grid[i][j] - '0'].push_back(f(i, j));
				cnt[grid[i][j] - '0']++;
			}
		}
	}
	
	bool fl = true;
	while (fl) {
		fl = false;
		
		for (int i = 1; i <= p; i++) {
			for (int _ = 0; _ < speed[i]; _++) {
				std::vector<int> ncur;
				for (auto& pos: cur[i]) {
					int x = pos / m, y = pos % m;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == '.') {
							grid[nx][ny] = '0';
							cnt[i]++;
							ncur.push_back(f(nx, ny));
						}
					}
				}
				
				cur[i] = ncur;
				if (cur[i].size() == 0) {
					break;
				}
			}
			
			if (cur[i].size() > 0) {
				fl = true;
			}
		}
	}
	
	for (int i = 1; i <= p; i++) {
		std::cout << cnt[i] << ' ';
	}
	return 0;
}
