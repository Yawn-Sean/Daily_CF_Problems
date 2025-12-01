#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool sol() {
	int n, m; std::cin >> n >> m;
	std::vector grid(n, std::vector<int> (m));
	int res = 0;
	std::vector<std::array<int, 3>> tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> grid[i][j];
			res ^= grid[i][j] & 1;
			tmp.push_back({grid[i][j], i, j});
		}
	}

	std::sort(tmp.begin(), tmp.end());

	std::vector<std::vector<int>> to_fill(n, std::vector<int> (m, -1));

	for (auto &[v, x, y]: tmp) {
		int val = -1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			val = std::max(val, to_fill[nx][ny]);
		}
		to_fill[x][y] = val + 1;
		res ^= (val + 1) & 1;
	}
	return res;
}

void soviet() {
	if (sol()) std::cout << "Yes\n";
	else std::cout << "No\n";
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
