#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> adj(n + 1), deg(n + 1), siz(n + 1, 1);
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		adj[u] ^= v;
		adj[v] ^= u;
		deg[u]++;
		deg[v]++;
	}
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
	for(int i = 1; i <= n; ++i){
		if(deg[i] == 1) q.push({1, i});
	}
	for(int i = 1; i < n; ++i){
		auto [val, id] = q.top();
		q.pop();
		int v = adj[id];
		if(siz[v] < val){
			cout << "NO\n";
			return 0;
		}
		--deg[v];
		adj[v] ^= id;
		siz[v] += val;
		if(deg[v] == 1) q.push({siz[v], v});
	}
	cout << "YES\n";
	return 0;
}
