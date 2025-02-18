#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (auto&x:p){cin>>x;}
	
	vector<vector<int>> path(n+1);
	for (int i = 0; i < m; i++) {
		int u,v;
		cin>>u>>v;
		path[u].push_back(v);
	}
	
	vector<int> vis(n+1,0);
	vis[p.back()]=1;
	
	int cnt = 1;
	for (int i = n - 2; i >= 0; i--) {
		int v = 0;
		for (auto&j: path[p[i]]) {
			v += vis[j];
		}
		
		if (v < cnt) {
			vis[p[i]] = 1;
			cnt++;
		}
	}
	cout << n - cnt;
	return 0;
}
