#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> path(n);
	vector<int> is_root(n, 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back(v);
		is_root[v] = 0;
	}
	
	vector<int> a(n);
	vector<int> used(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		used[a[i]] = 1;
	}
	
	vector<int> ans(n, -1), order;
	stack<int> stk;
	
	for (int i = 0; i < n; i++) {
		if (is_root[i]) { stk.push(i); }
	}
	
	while (!stk.empty()) {
		int u = stk.top();
		stk.pop();
		if (used[u]) {
			order.push_back(u);
			ans[u] = u;
		}	
		for (auto& v: path[u]) {
			ans[v] = ans[u];
			stk.push(v);
		}
	}
	
	if (ans != a) {
		cout << -1;
	} else {
		reverse(order.begin(), order.end());
		cout << order.size() << '\n';
		for (auto& x: order) {
			cout << x + 1 << '\n';
		}
	}
	return 0;
}
