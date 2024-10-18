#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<int>> pt(n, vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> pt[i][j];
		}
	}
	if (n > 11) {
		cout << 0 << '\n';
		return 0;
	}
	
	vector<int> ans;
	for (int a = 0; a < n; a++) {
		bool ok = true;
		for (int b = 0; ok and b < n; b++) {
			if (b == a) continue;
			for (int c = 0; ok and c < n; c++) {
				if (c == a or c == b) continue;
				
				int cur = 0;
				for (int d = 0; d < 5; d++) {
					int dx = pt[b][d] - pt[a][d];
					int dy = pt[c][d] - pt[a][d];
					cur += dx * dy;
				}
				if (cur > 0) {
					ok = false;
				}
				
			}
		}
		if (ok) {
			ans.push_back(a + 1);
		}
	}
	cout << ans.size() << '\n';
	for (auto& x: ans) {
		cout << x << ' ';
	}
	cout << '\n';
    return 0;
}
