#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	
	int ans = m, idx = -1;
	for (int i = 0; i < n - 1; i++) {
		vector<int> tmp;
		for (int j = 0; j < m; j++) {
			tmp.push_back(-grid[j][i] + grid[j][n - 1]);
		}
		sort(tmp.begin(), tmp.end());
		
		i64 cur = 0;
		int l = 0;
		for (int k = 0; k < m; k++) {
			cur += tmp[k];
			if (cur <= 0) {
				l = k + 1;
			}
		}
		if (m - l < ans) {
			ans = m - l; // l长度保留 剩下不要
			idx = i;
		}
	}
	
	if (ans == 0) {
		cout << 0 << '\n';
	} else {
		vector<int> ids(m);
		iota(ids.begin(), ids.end(), 0);
		
		sort(ids.begin(), ids.end(), [&](int i, int j) {
			return grid[i][n - 1] - grid[i][idx] > grid[j][n - 1] - grid[j][idx];
		});
		
		cout << ans << '\n';
		for (int i = 0; i < ans; i++) {
			cout << ids[i] + 1 << ' ';
		}
		cout << '\n';
	}

    return 0;
}
