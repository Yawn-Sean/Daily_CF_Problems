#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	set<pair<int, int>> vis;
	int x, y;
	for (int i = 0; i < m; i ++) {
		cin >> x >> y;
		x --; y --;
		if (x < y) swap(x, y);
		vis.insert({x, y});
	}
	if (m == 1LL * n * (n - 1) / 2) {
		cout << "NO" << endl;
		return;
	}
	bool f = false;
	for (int i = 0; i < n && !f; i ++) {
		for (int j = 0; j < i && !f; j ++) {
			if (!vis.count({i, j})) {
				x = i;
				y = j;
				f = true;
			}
		}
	}
	vector<int> ans(n);
	ans[x] = n, ans[y] = n - 1;
	for (int i = 0, cur = 1; i < n; i ++) {
		if (!ans[i]) ans[i] = cur ++;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << " \n"[i == n - 1];
	}
	ans[y] = n;
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << " \n"[i == n - 1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
