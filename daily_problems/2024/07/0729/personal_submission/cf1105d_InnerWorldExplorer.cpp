#include <bits/stdc++.h>
using namespace std;

const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> s(p);
	for (int i = 0; i < p; i ++) {
		cin >> s[i];
	}

	auto f = [&](int i, int j) {
		return i * m + j;
	};

	vector<string> grid(n);
	vector<int> cnt(p);
	vector<vector<int>> pos(p, vector<int>());
	for (int i = 0; i < n; i ++) {
		cin >> grid[i];
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] != '.' && grid[i][j] != '#') {
				cnt[grid[i][j] - '0' - 1] ++;
				pos[grid[i][j] - '0' - 1].push_back(f(i, j));
			}
		}
	}

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < p; i ++) {
			for (int _ = 0; _ < s[i]; _ ++) {
				vector<int> npos;
				for (auto idx : pos[i]) {
					int x = idx / m, y = idx % m;
					for (int j = 0; j < 4; j ++) {
						int nx = x + dx[j], ny = y + dy[j];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
							npos.push_back(f(nx, ny));
							grid[nx][ny] = i + '0';
							cnt[i] ++;
						}
					}
				}
				if ((int)npos.size() > 0) {
					flag = true;
					pos[i] = npos;
				}else{
					break;
				}
			}
		}
	}
	for (int i = 0; i < p; i ++) cout << cnt[i] << " \n"[i == p - 1];
	return 0;
}
