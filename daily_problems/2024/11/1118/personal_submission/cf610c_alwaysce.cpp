#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	function<vector<vector<int>>(int)> dfs = [&](int k) -> vector<vector<int>> {
		if (k == 1) {
			return vector<vector<int>>(1, vector<int>(1, 1));
		}
		
		vector<vector<int>> h = dfs(k - 1);
		int r = h.size(), c = h[0].size();
		vector<vector<int>> curh(2 * r, vector<int>(2 * c));
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				curh[i][j] = h[i][j];
			}
			for (int j = c; j < 2*c; j++) {
				curh[i][j] = h[i][j - c];
			}
		}
		for (int i = r; i < 2*r; i++) {
			for (int j = 0; j < c; j++) {
				curh[i][j] = h[i - r][j];
			}
			for (int j = c; j < 2*c; j++) {
				curh[i][j] = -h[i - r][j - c];
			}
		}
		return curh;
	};
	
	auto ans = dfs(n + 1);
	for (auto& row: ans) {
		for (auto& v: row) {
			cout << (v == 1 ? '+' : '*');
		}
		cout << '\n';
	}
    return 0;
}
