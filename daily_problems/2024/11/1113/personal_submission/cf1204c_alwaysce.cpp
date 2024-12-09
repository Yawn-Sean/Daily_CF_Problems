#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<vector<int>> path(n, vector<int>(n, n + 1));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		path[i][i] = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				path[i][j] = 1;
			}
		}
	}
	
	int m;
	cin >> m;
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i];
		--p[i];
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}
	
	vector<int> ans = {p[0]};
	int idx = 0;
	while (idx < m - 1) {
		int nidx = idx;
		while (nidx < m - 1 and path[p[idx]][p[nidx + 1]] == path[p[idx]][p[nidx]] + 1) {
			++nidx;
		}
		ans.push_back(p[nidx]);
		idx = nidx;
	}
	
	cout << ans.size() << '\n';
	for (auto& x: ans) {
		cout << x + 1 << ' ';
	}
    return 0;
}
