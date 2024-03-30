#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;

void dfs(int root, vector<bool>& vis, vector<int>& g, vector<int> &temp) {
	temp.emplace_back(root);
	if (vis[root]) return;
	vis[root] = true;
	dfs(g[root], vis, g, temp);
	return;
}

int calculate(vector<int>& temp, vector<int>& w) {
	int num = temp.back();
	int cnt = 1e9;
	bool flag = false;
	for (int i = 0; i < temp.size() - 1; i++) {
		if (temp[i] != num && !flag) continue;
		flag = true;
		cnt = min(cnt, w[temp[i]]);
	}
	return cnt == 1e9 ? 0 : cnt;
}

void solve() {
	int n; cin >> n;
	int ans = 0;
	vector<int> w(n + 1), g(n + 1);
	vector<bool> vis(n + 1);
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> g[i];
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vector<int> temp;
		dfs(i, vis, g, temp);
		ans += calculate(temp, w);
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
