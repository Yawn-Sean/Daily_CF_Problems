#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> colors(m);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		colors[x-1].push_back(i);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (colors[i].size() > 0) {
			// 最多可以删掉k个
			int x = colors[i].size();
			int left = 0;
			for (int right = 0; right < x; right++) {
				while (true) {
					int cnt = right - left + 1;
					int len = colors[i][right] - colors[i][left] + 1;
					if (left >= right or len - cnt <= k) {
						break;
					} else {
						++left;
					}
				}
				ans = max(ans, right - left + 1);
			}
		}
	}
	
	cout << ans;
	return 0;
}
