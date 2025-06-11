#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> scores(m + 1);	
	for (int i = 0; i < n; i++) {
		int si, ri;
		cin >> si >> ri;
		scores[si].push_back(ri);
	}
	for (int i = 1; i <= m; i++) {
		if (scores[i].size()) {
			sort(scores[i].rbegin(), scores[i].rend());
		}
 	}
 	
	// 选n个人的最大值
	vector<int> score_mx(n + 1);
	for (int i = 1; i <= m; i++) {
		int cur = 0;
		int k = scores[i].size();
		if (k) {
			for (int j = 0; j < k; j++) {
				cur += scores[i][j];
				if (cur > 0) {
					score_mx[j + 1] += cur;
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, score_mx[i]);
	}
	cout << ans;
	return 0;
}
