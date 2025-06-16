#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> fa(n + 1);
	vector adj(n + 1, vector <int> ());
	for(int i = 2; i <= n; ++i){
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	for(int i = 1; i <= n; ++i){
		sort(adj[i].begin(), adj[i].end());
	}
	vector <int> euler;
	vector <int> siz(n + 1, 0);
	vector <int> pos(n + 1, 0);
	auto dfs = [&](auto&& self, int cur) -> void {
		pos[cur] = euler.size();
		euler.push_back(cur);
		siz[cur] = 1;
		for(int to : adj[cur]){
			self(self, to);
			siz[cur] += siz[to];
		}
	};
	dfs(dfs, 1);
	for(int i = 1; i <= m; ++i){
		int u, k;
		cin >> u >> k;
		if(siz[u] < k) cout << -1 << "\n";
		else cout << euler[pos[u] + k - 1] << "\n";
	}
	return 0;
}