#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 n, k;
	cin >> n >> k;
	
	if (n > k * (k - 1)) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		
		vector<pair<int,int>> ans;
		for (i64 sm = 0; sm <= 2 * (k - 1) and (i64)ans.size() < n; sm++) {
			i64 min_i = max(0ll, sm - (k - 1));
			i64 max_i = min(k - 1, sm);
			
			for (int i = min_i; i <= max_i and (i64)ans.size() < n; i++) {
				int j = sm - i;
				if (i != j) {
					ans.push_back({i, j});
				}
			}
		}
		
		for (auto& pr: ans) {
			cout << pr.first + 1 << ' ' << pr.second + 1 << '\n';
		}
	}
	
    return 0;
}
