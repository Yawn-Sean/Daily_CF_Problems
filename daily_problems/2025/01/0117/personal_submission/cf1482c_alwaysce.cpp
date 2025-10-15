#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
		
	while (t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> path(m);
		vector<int> cnt(n + 1), ans(m);
		
		bool find = true;
		for(int i = 0; i < m; i++) {
			int k;
			cin >> k;
			path[i].resize(k);
			for (int j = 0; j < k; j++) { cin >> path[i][j]; }
			
			if (k == 1) {
				++cnt[path[i][0]];
				ans[i] = path[i][0];
				if (cnt[path[i][0]] > (m+1)/2) {
					find = false;
				}
			}
		}
		
		for (int i = 0; i < m and find; i++) {
			if (path[i].size() > 1) {
				int mn = -1, choose = -1;
				for (auto& j: path[i]) {
					if (cnt[j] > mn and (cnt[j]+1) <= (m+1)/2) {
						mn = cnt[j];
						choose = j;
					}
				}
				if (choose == -1) { find = false; break; }
				else {
					++cnt[choose];
					ans[i] = choose;
				}
			}
		}
		
		if (find) {
			cout << "YES\n";
			for (auto&x: ans) { cout << x << ' '; }
			cout << '\n';
		} else {
			cout << "NO\n";
		}
		
	}
	return 0;
}
