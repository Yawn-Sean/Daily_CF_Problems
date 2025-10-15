#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	vector<vector<int>> ls(n, vector<int>(m)), gt(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		set<int> s;
		for (int j = 0; j < m; j++) {
			s.insert(a[i][j]);
		}
		vector<int> v(s.begin(), s.end());
		for (int j = 0; j < m; j++) {
			int idx = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
			// < a[i][j] = [0, idx-1] [idx+1, m-1]
			ls[i][j] = idx;
			gt[i][j] = (int)v.size() - idx - 1;
		} 
	}
	
	vector<vector<int>> ans(n, vector<int>(m));
	for (int j = 0; j < m; j++) {
		set<int> s;
		for (int i = 0; i < n; i++) {
			s.insert(a[i][j]);
		}
		vector<int> v(s.begin(), s.end());
		for (int i = 0; i < n; i++) {
			int idx = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
			// < a[i][j] = [0, idx-1] [idx+1, m-1]
			int lo = idx, hi = (int)v.size() - 1 - idx;
			ans[i][j] = max(ls[i][j], lo) + 1 + max(gt[i][j], hi);
		} 
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
