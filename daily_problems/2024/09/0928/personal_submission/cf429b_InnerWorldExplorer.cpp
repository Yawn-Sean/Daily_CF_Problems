#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (auto &v : a) {
		for (auto &x : v) {
			cin >> x;
		}
	}
	vector<vector<int>> f1(n + 2, vector<int>(m + 2)), f2(n + 2, vector<int>(m + 2));
	vector<vector<int>> g1(n + 2, vector<int>(m + 2)), g2(n + 2, vector<int>(m + 2));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			f1[i][j] = max(f1[i - 1][j], f1[i][j - 1]) + a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = m; j >= 1; j --) {
			f2[i][j] = max(f2[i][j + 1], f2[i - 1][j]) + a[i - 1][j - 1];
		}
	}
	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= m; j ++) {
			g1[i][j] = max(g1[i + 1][j], g1[i][j - 1]) + a[i - 1][j - 1];
		}
	}
	for (int i = n; i >= 1; i --) {
		for (int j = m; j >= 1; j --) {
			g2[i][j] = max(g2[i + 1][j], g2[i][j + 1]) + a[i - 1][j - 1];
		}
	}
	
	int ans = 0;
	for (int i = 1; i < n - 1; i ++) {
		for (int j = 1; j < m - 1; j ++) {
			int cnt1 = f1[i][j + 1] + g1[i + 1][j] + g2[i + 2][j + 1] + f2[i + 1][j + 2];
			int cnt2 = f1[i + 1][j] + g1[i + 2][j + 1] + g2[i + 1][j + 2] + f2[i][j + 1];
			ans = max(ans, max(cnt1, cnt2));
		}
	}
	cout << ans << endl;
	return 0;
}
