#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 选两棵不相交的子树
	// 子树的权重和最大
	int n;
	cin >> n;
	vector<i64> weight(n);
	for (auto& x: weight) { cin >> x; }
	
	vector<vector<int>> path(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	
	vector<int> fa(n, -1), order, stk = {0};
	while (!stk.empty()) {
		int u = stk.back();
		stk.pop_back();
		
		order.push_back(u);
		for (auto& v: path[u]) {
			if (fa[u] != v) {
				fa[v] = u;
				stk.push_back(v);
			}
		}
	}
	
	vector<i64> dp(n, 0), dp1(n, -inf), dp2(n, -inf);
	i64 ans = -inf;
	
	reverse(order.begin(), order.end());
	
	// 对于 LCA 连出的不同的子树分别求最大子树和
	for (auto& i: order) {
		dp[i] += weight[i];
		if (i > 0) {
			int p = fa[i];
			dp[p] += dp[i];
			
			i64 v = max(dp[i], dp1[i]);
			if (v >= dp1[p]) {
				dp2[p] = v;
				swap(dp1[p], dp2[p]);
			} else if (v > dp2[p]) {
				dp2[p] = v;
			}
		}
		
		if (dp2[i] > -inf) {
			ans = max(ans, dp1[i] + dp2[i]);
		}
	}
	
	if (ans == -inf) {
		cout << "Impossible";
	} else {
		cout << ans;
	}
    return 0;
}
