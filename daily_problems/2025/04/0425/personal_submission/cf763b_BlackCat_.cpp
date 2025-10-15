/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int s1, s2, t1, t2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') {
				s1 = i;
				s2 = j;
			}
			else if (a[i][j] == 'T') {
				t1 = i;
				t2 = j;
			}
		}
	}
	std::queue<std::array<int, 4>> q;
	q.push({s1, s2, 0, 0});
	q.push({s1, s2, 0, 1});
	q.push({s1, s2, 0, 2});
	q.push({s1, s2, 0, 3});
	std::vector vis(n, std::vector (m, std::vector(3, std::vector<int>(4, 0))));
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	while (!q.empty()) {
		auto [x, y, z, f] = q.front();
        q.pop();
		if (z > 2) {
			continue;
		}
		if (vis[x][y][z][f]) {
			continue;
		}
		vis[x][y][z][f] = 1;
		if (x == t1 && y == t2) {
			std::cout << "YES" << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}
			if (a[nx][ny] == '*') {
				continue;
			}
			q.push({nx, ny, z + (i != f), i});

		}
	}
	std::cout << "NO" << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
