#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
int inf = 1e9;

int ask(int a, int b) {
	cout << "? " << a << ' ' << b << '\n';
	cout.flush();
	int r;
	cin >> r;
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		找到树的直径中点x
		距离x < k的每个点y deg[y] > 3
		距离x = k的每个点 都是叶子节点 deg[y] = 1
	*/
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> path(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	
	stack<int> stk;
	vector<int> dis(n, -1), dis1(n, -1);
	
	for (int i = 0; i < n; i++) {
		if (path[i].size() == 1) {
			stk.push(i);
			dis[i] = 0; // 叶子初始化为d=0
			while (!stk.empty()) {
				int u = stk.top();
				stk.pop();
				for (auto& v: path[u]) {
					if (dis[v] == -1) {
						dis[v] = dis[u] + 1;
						stk.push(v);
					}
				}
			}
			
			// 距离最大的另一个端点	
			int nd = (max_element(dis.begin(), dis.end()) - dis.begin());
			stk.push(nd);
			
			dis1[nd] = 0;
			while (!stk.empty()) {
				int u = stk.top();
				stk.pop();
				for (auto& v: path[u]) {
					if (dis1[v] == -1) {
						dis1[v] = dis1[u] + 1;
						stk.push(v);
					}
				}
			}
			
			int rt = -1;
			for (int i = 0; i < n; i++) {
				if (dis[i] == k and dis1[i] == k) {
					rt = i;
				}
			}
			
			if (rt == -1) {
				cout << "No\n";
				return 0;
			}
			
			// 找到中点后向外扩散
			vector<int> to_center(n, -1);
			stk.push(rt);
			to_center[rt] = 0;
			while (!stk.empty()) {
				int u = stk.top();
				stk.pop();
				for (auto& v: path[u]) {
					if (to_center[v] == -1) {
						to_center[v] = to_center[u] + 1;
						stk.push(v);
					}
				}
			}
			
			// 中心点的度数>=3
			if (path[rt].size() < 3) {
				cout << "No\n";
				return 0;
			}
			
			for (int i = 0; i < n; i++) {
				// 叶子节点的距离==k
				if (path[i].size() == 1) {
					if (to_center[i] != k) {
						cout << "No\n";
						return 0;
					}
				} else if (i != rt and path[i].size() <= 3) {
					// 再次向外扩展的点度数>=3
					cout << "No\n";
					return 0;
				}
			}
			
			cout << "Yes\n";
			return 0;
		}
	}
	
	cout << "No\n";
    return 0;
}
