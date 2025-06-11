#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> colors(n);
	for (auto& c: colors) {
		cin >> c;
	}
	
	vector<vector<int>> path(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	
	auto op = [&](int x) {
		colors[x] = -colors[x];
		cout << x + 1 << ' ';
	};
	
	function<void(int,int)> dfs = [&](int u, int p) {
		// 先走过树上的每个点 dfs
		if (u > 0) {
			op(u);
		}
		for (auto& v: path[u]) {
			if (v != p) {
				dfs(v, u);
			}
		}
		
		// u为 非根节点 -> p
		if (u > 0) {
			op(p);
		}
		
		// 如果当前节点颜色不对
		// p->u刷一次 然后p再刷一次 u一下就不考虑了
		if (colors[u] != 1) {
			if (u > 0) {
				op(u); op(p);
			} else {
				// 树根 那么随便找一个点
				// 走下去-> 走回来 -> 再走下去
				int v = path[u][0];
				op(v);
				op(u);
				op(v);
			}
		}
	};
	cout << 1 << ' ';
	dfs(0, -1);
	return 0;
}
