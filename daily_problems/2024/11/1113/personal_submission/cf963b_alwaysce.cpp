#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	/*
		从叶子节点开始考虑
		
		叶子节点度数=1
		叶子不能删除
		
		每次删边数量=偶数/节点总数=奇数
		
		每次从底部向上找到一个偶数节点
		删除这偶数条边
		x+y+1 = n, n是奇数
		
		x子树内每个节点的度数都是奇数 => 
		剩余子树偶数条边 => 拆完之后每个子树也是奇数个节点
		
	*/
	vector<int> deg(n + 1), vis(n + 1);
	int root = 0;
	vector<vector<int>> path(n + 1);
	
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		if (u == 0) {
			root = i;
		} else {
			deg[i] ^= 1;
			deg[u] ^= 1;		
			path[u].push_back(i);
		}
	}
	
	if (n % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	
	function<void(int)> print_ans = [&](int u) {
		cout << u << '\n';
		vis[u] = 1;
		for (auto& v: path[u]) {
			if (!vis[v]) {
				print_ans(v);
			}
		}
	};
	
	function<void(int,int)> dfs = [&](int u, int p) {
		for (auto& v: path[u]) {
			dfs(v, u);
		}
		if (deg[u] == 0) {
			if (p != -1) {
				deg[p] ^= 1;
			}
			print_ans(u);
		}
	};
	
	dfs(root, -1);
    return 0;
}
