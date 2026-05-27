#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<set<array<int, 3>>>> grid(2 * n + 1, vector<set<array<int, 3>>>(2 * m + 1));

	vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	vector<string> dir_str = {"LEFT", "RIGHT", "UP", "DOWN"};
	vector<int> cur = {-1, -1, -1};

	auto move = [&] (int idx) -> bool {
		if (idx < 4) cout << "MOVE " << dir_str[idx] << endl;
		else cout << "BACK" << endl;

		string ret; cin >> ret;
		if (ret == "EXIT") exit(0);
		if (ret == "FAIL") return false;
		return true;
	};

	auto dfs = [&] (auto &self, int x, int y) -> void {
		for (int i = 0; i < 4; i ++) {
			if (cur.back() == (i ^ 1)) continue;

			cur.emplace_back(i);
			auto [dx, dy] = dirs[i];
			int nx = x + dx, ny = y + dy;
			array<int, 3> last_3 = {cur.end()[-3], cur.end()[-2], cur.end()[-1]};

			if (grid[nx][ny].find(last_3) == grid[nx][ny].end() && move(i)) {
				grid[nx][ny].insert(last_3);
				self(self, nx, ny);
				move(4);
			}

			cur.pop_back();
		}
	};

	dfs(dfs, n, m);

	return 0;
}