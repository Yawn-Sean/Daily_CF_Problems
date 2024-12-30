#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> ed[1 << 18]; 
int vis[1 << 18] {}, st[1 << 18] {};
void dfs(int x) {
	if (vis[x] != 0) return;
	vis[x] = 1;
	for (int v : ed[x]) {
		dfs(v);
	}
	return;
}
void yrlpSolve() {
	int n, m, d; cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	vector<int> v;
	vis[1] = 1; 
	for (int x : ed[1]) {
		if (vis[x] != 0) continue;
		v.push_back(x);
		dfs(x);
		vis[x] = 2;
	}
	if (v.size() > d or d > ed[1].size()) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl; 
	queue<int> q;
	d -= v.size();
	for (int x : ed[1]) {
		if (vis[x] == 2 || d) {
			q.push(x); st[x] = 1;
			cout << 1 << " " << x << endl;
			d -= (vis[x] == 1);
		} 
	}
	
	st[1] = 1;
 	while (q.size()) {
		int s = q.size();
		while (s--) {
			int x = q.front(); q.pop();
			for (int v : ed[x]) {
				if (st[v] == 0) {
					cout << x << " " << v << endl;
					st[v] = 1;
					q.push(v);
				}
			}
		}
	}	
    return;     
}

signed main() {
    int t = 1; //cin >> t;
	while (t--) yrlpSolve();
}
