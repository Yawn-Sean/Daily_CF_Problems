#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// Inequalities are easy to be dealt with, so process the equalities first.	
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	
	DSU d(n + m + 1);
	// ai ... bj
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '=') {
				d.merge(i, n + j);
			}
		}
	}
	
	vector<int> ind(n + m + 1);
	vector<vector<int>> path(n + m + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '>') {
				int ai = d.find(i);
				int bj = d.find(n + j);
				path[bj].push_back(ai);
				ind[ai]++;
			} else if (grid[i][j] == '<') {
				int ai = d.find(i);
				int bj = d.find(n + j);
				path[ai].push_back(bj);
				ind[bj]++;
			}
		}
	}
	
	queue<int> q;
	vector<int> ans(n + m);
	for (int i = 0; i < n + m; i++) {
		if (ind[i] == 0) {
			q.push(i);
			ans[i] = 1;
		}
	}
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& nxt: path[cur]) {
			--ind[nxt];
			if (ind[nxt] == 0) {
				q.push(nxt);
				ans[nxt] = ans[cur] + 1;
			}
		}
	}
	for (int i = 0; i < n + m; i++) {
		ans[i] = max(ans[i], ans[d.find(i)]);
	}

	bool ok = true;
	for (int i = 0; i < n + m; i++) {
		if (ans[i] == 0) {
			ok = false;
		}
	}
	if (ok) {
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		for (int i = 0; i < m; i++) {
			cout << ans[n + i] << ' ';
		}
		cout << '\n';
	} else {
		cout << "No\n";
	}
	
	return 0;
}
