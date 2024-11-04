#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> c(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> p[i];
	}
	
	int k;
	cin >> k;
	vector<int> r(k);
	for (auto& x: r) { cin >> x; }
	
	vector<int> table_id(k);
	iota(table_id.begin(), table_id.end(), 0);
	sort(table_id.begin(), table_id.end(), [&](int i, int j) {
		return r[i] < r[j];
	});
	

	int tot = 0;
	vector<pair<int,int>> ans;
	vector<int> used(n, 0);
	for (int i = 0; i < k; i++) {
		int mx = 0, mx_idx = -1;
		for (int j = 0; j < n; j++) {
			if (!used[j] and c[j] <= r[table_id[i]]) {
				if (p[j] > mx) {
					mx = p[j];
					mx_idx = j;
				}
			}
		}
		if (mx > 0) {
			tot += mx;
			ans.push_back({mx_idx + 1, table_id[i] + 1});	
			used[mx_idx] = 1;		
		}
	}
	
	cout << ans.size() << ' ' << tot << '\n';
	for (auto& pr: ans) {
		cout << pr.first << ' ' << pr.second << '\n';
	}
	return 0;
}
