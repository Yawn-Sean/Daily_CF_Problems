#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector adj(n + 1, vector <int> ());
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector <int> cents;
	vector <int> siz(n + 1);
	auto dfs = [&](auto&& self, int cur, int fa) -> void {
		siz[cur] = 1;
		int mx = 0;
		for(int to : adj[cur]){
			if(to == fa) continue;
			self(self, to, cur);
			siz[cur] += siz[to];
			mx = max(mx, siz[to]);
		}
		mx = max(mx, n - siz[cur]);
		if(mx * 2 <= n) cents.push_back(cur);
	};
	auto dfs2 = [&](auto&&self, int cur, int fa) -> bool {
		siz[cur] = 1;
		vector <int> sizs;
		for(int to : adj[cur]){
			if(to == fa) continue;
			auto res = self(self, to, cur);
			if(!res) return 0;
			siz[cur] += siz[to];
			sizs.push_back(siz[to]);
		}
		sort(sizs.begin(), sizs.end());
		int sm = 1;
		for(auto i : sizs){
			if(sm < i) return 0;
			sm += i;
		}
		return 1;
	};
	dfs(dfs, 1, 0);
	for(auto cent : cents){
		if(dfs2(dfs2, cent, 0)){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}