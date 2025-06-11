#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		最短路径树 SPT
	*/
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<pair<int,int>> > path(n);
	vector<int> dis(n, inf);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back({v, i});
		path[v].push_back({u, i});
	}
	
	auto bfs = [&](int u) {
		queue<int> q;
		dis[u] = 0;
		q.push(u);
		
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			 
			for (auto& pr: path[x]) {
				int v = pr.first;
				if (dis[v] > dis[x] + 1) {
					dis[v] = dis[x] + 1;
					q.push(v);
				}
			}
		}
	};
	
	bfs(0);
	// for (auto& d: dis) { cout << d << ' '; }
	// cout << '\n';
	
	vector<char> res(m, '0');
	vector<string> ans;	
	vector<vector<int>> ok(n);
	
	for (int u = 1; u < n; u++) {
		// u<-v v是u的(可选)前一跳
		// 一个点在 SPT 中的父节点是在原图跑 dij过程中能够更新它的点中的任意一个。
		for (auto& pr: path[u]) {
			int v = pr.first, edge_idx = pr.second;
			if (dis[u] == dis[v] + 1) {
				ok[u].push_back(edge_idx);
			}
		}
		// cout << u << ": ";
		// for (auto& i: ok[u]) {
			// cout << i << ' ';
		// }
		// cout << '\n';
	}
	
	function<void(int)> dfs = [&](int u) {
		if ((int)ans.size() >= k) {
			return;
		}
		if (u == n) {
			string tmp;
			for (auto& ch: res) {
				tmp.push_back(ch);
			}
			ans.push_back(tmp);
			return;
		}
		
		for (auto& edge_idx: ok[u]) {
			res[edge_idx] = '1';
			dfs(u + 1);
			res[edge_idx] = '0';
		}
		return;
	};
	
	
	dfs(1);

	cout << ans.size() << '\n';
	for (auto& s: ans) {
		cout << s << '\n';
	}

    return 0;
}
