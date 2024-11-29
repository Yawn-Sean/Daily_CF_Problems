#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	
	vector<vector<int>> dislike(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		dislike[u].push_back(v);
		dislike[v].push_back(u);
	}
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return (x[i] - y[i]) < (x[j] - y[j]);
	});
	// for (auto& o: order) {
		// cout << o << ' ';
	// }
	// cout << '\n';
	
	// min{xi + yj, xj + yi} = yi+yj + min{xi-yi, xj-yj}
	// 排序之后对于固定的o
	// j > o 需要计算 xj + yo
	// j < o 需要计算 yj + xo
	vector<i64> pre(n + 1), suf(n + 1), ans(n);
	for (int i = n - 1; i >= 0; i--) {
		int o = order[i];
		suf[i] = suf[i + 1] + y[o];
	}
	
	for (int i = 0; i < n; i++) {
		// 按照xi-yi排序
		int o = order[i];
		
		// 前面计算 xo + sum(yj)
		i64 preS = 1ll * i * y[o] + pre[i];
		// 后面计算 yo + sum(xj)
		i64 sufS = 1ll * (n - i - 1) * x[o] + suf[i + 1];		
		
		ans[o] = preS + sufS;
		pre[i + 1] = pre[i] + x[o];
	}
	
	for (int i = 0; i < n; i++) {
		for (auto& di: dislike[i]) {
			ans[i] -= 1ll * min(x[i] + y[di], x[di] + y[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
