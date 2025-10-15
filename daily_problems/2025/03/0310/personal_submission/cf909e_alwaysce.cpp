#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	/*
	对于这组任务中的每一个任务，
	它所依赖的所有任务都必须已经完成或包含在这组任务中
	
	每次都批量处理
	*/
	vector<int> nums(n);
	for (auto&x: nums) { cin >> x; }
	
	vector<vector<int>> path(n);
	vector<int> ind(n);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		path[u].emplace_back(v);
		++ind[v];
	}
	
	queue<int> q0, q1;
	for (int i = 0; i < n; i++) {
		if (ind[i] == 0) {
			if (nums[i] == 0) {
				q0.push(i);
			} else {
				q1.push(i);
			}
		}
	}
	
	int ans = 0;
	while (!q0.empty() || !q1.empty()) {
		while (!q0.empty()) {
			int u = q0.front();
			q0.pop();
			for (auto&v: path[u]) {
				--ind[v];
				if (ind[v] == 0) {
					if (nums[v]) { q1.push(v); }
					else { q0.push(v); }
				}
			}
		}
		if (!q1.empty()) { ++ans; }
		while (!q1.empty()) {
			int u = q1.front();
			q1.pop();
			for (auto&v: path[u]) {
				--ind[v];
				if (ind[v] == 0) {
					if (nums[v]) { q1.push(v); }
					else { q0.push(v); }
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}
