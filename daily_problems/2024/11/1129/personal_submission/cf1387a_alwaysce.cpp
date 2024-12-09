#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	/*
		n个节点 m条边
		黑色边的端点sum=1
		红色边端点sum=2
		求解分配节点权重的方式
		
		对于一个分量内部
		某个点我们定为x
		那么其他的点的权重都可以表示为
		-x+b / x+b的形式
		{x-x+b}=1/2
		{x+x+b}=1/2
		
		出现同号的一条边就可以求解出x
		否则都是异号就需要找x
		x, -x+b1, 
		(0), (-b1), (-b2)
		sort 然后贪心中位数就是绝对值最小的x
	*/	
	vector<int> us(m), vs(m), ws(m);
	vector<vector<int>> path(n);
	
	for (int i = 0; i < m; i++) {
		cin >> us[i] >> vs[i] >> ws[i];
		us[i]--; vs[i]--;
		path[us[i]].push_back(i);
		path[vs[i]].push_back(i);
	}
	
	vector<int> k(n), b(n), vis(n, 0);
	vector<double> ans(n);
	
	for (int i = 0; i < n; i++) {
		if (k[i] == 0) {
			// 没有访问过的分量随便给一个kx+b的k
			// x为我们假设选定的一个实数
			k[i] = 1;
			
			bool flag = false;
			double val = 0.0;
			vector<int> vals, edge_ids;
			
			function<void(int)> dfs = [&](int u) {
				vals.push_back(k[u] * b[u]);
				for (auto& eid: path[u]) {
					edge_ids.push_back(eid);
					
					int v = us[eid] + vs[eid] - u;
					int w = ws[eid];
					if (k[v] == 0) {
						k[v] = -k[u];
						b[v] = w - b[u];
						dfs(v);		
					} else if (k[v] == k[u]) {
						// 一次项系数一样 可以求出具体数值
						flag = true;
						val = 1.0 * (w - b[u] - b[v]) / (k[u] + k[v]); 
					}
				}
				
			};
			
			
			dfs(i);
			if (not flag) {
				// 说明需要中位数贪心
				sort(vals.begin(), vals.end());
				val = -vals[vals.size() / 2];
			}
			
			// 找到的x
			ans[i] = val;
			
			function<void(int)> dfs2 = [&](int u) {
				for (auto& eid: path[u]) {
					int v = us[eid] + vs[eid] - u;
					int w = ws[eid];
					if (!vis[v]) {
						vis[v] = 1;
						ans[v] = w - ans[u];
						dfs2(v);
					}
				}
			};
			
			dfs2(i);
			for (auto& eid: edge_ids) {
				if (abs(ans[us[eid]] + ans[vs[eid]] - ws[eid]) > 0.1) {
					cout << "NO\n";
					return 0;
				}
			}
			
		}
	}
	cout << "YES\n";
	for (auto& x: ans) {
		cout << x << ' ';
	}
	return 0;
}

