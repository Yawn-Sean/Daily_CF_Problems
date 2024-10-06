#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(n + 1);
	for (int i = 1; i <= n; i++) { cin >> c[i]; }
	
	DSU d(n + 1);
	vector<int> used(n + 1);
	map<int, map<int, int> > seen;
	
	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
		d.merge(l, r);
		used[l]++;
		used[r]++;
	}
	
	// ans += 联通分量size - 每个联通分量内部出现最多次的频率
	for (int i = 1; i <= n; i++) {
		if (used[i] > 0) {
			int fi = d.find(i);
			seen[fi][c[i]]++;
		}
	}
	
	int ans = 0;
	for (auto& pr: seen) {
		int sz = d.size(pr.first);
		int mx = 0;
		for (auto& vpr: pr.second) {
			int v = vpr.second;
			mx = max(mx, v);
		}
		ans += (sz - mx);
	}
	cout << ans;
	return 0;
}
