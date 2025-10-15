#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
		D->I->M->A->D
		有向图找环
		有环就是inf
		无环
			DIMA的路径长度有限
			从D开始dfs
	*/
	map<char,int> mp;
	mp['D'] = 0, mp['I'] = 1, mp['M'] = 2, mp['A'] = 3;
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			grid[i][j] = mp[tmp[j]];
		}
	}
	
	vector<vector<int>> path(n*m);
	vector<pair<int,int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	auto cal = [&](int x, int y) {
		return x * m + y;
	};
	
	vector<int> ind(n*m, 0), ans(n * m, -1);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (auto& pr: dirs) {
				int ni = i + pr.first, nj = j + pr.second;
				if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
					if ((grid[ni][nj] - grid[i][j] + 4) % 4 == 1) {
						path[cal(i, j)].emplace_back(cal(ni, nj));
						ind[cal(ni, nj)]++;
					}
				}
			}
		}
	}
	
	// 有向无环图 可以拓扑排序求长度
	// 注意起点一定是D 终点是A
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ind[cal(i, j)] == 0) {
				q.push(cal(i, j));
				ans[cal(i, j)] = grid[i][j];
				if (ans[cal(i, j)] == 0) {
					ans[cal(i, j)] = 4;
				}
			}
		}
	}
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto& v: path[u]) {
			--ind[v];
			ans[v] = max(ans[v], ans[u] + 1);
			if (ind[v] == 0) {
				q.push(v);
			}
		}
	}
	
	if (*max_element(ind.begin(), ind.end()) > 0) {
		cout << "Poor Inna!";
	} else {
		int res = (*max_element(ans.begin(), ans.end()) - 3) / 4;
		if (res > 0) {
			cout << res;
		} else {
			cout << "Poor Dima!";
		}
	}
	return 0;
}
