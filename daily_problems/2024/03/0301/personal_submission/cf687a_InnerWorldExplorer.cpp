#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	int u, v;
	for (int i = 0; i < m; i ++) {
		cin >> u >> v;
		u --; v --;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> side(n, -1);
	bool is_bipartite = true;
	queue<int> q;
	for (int st = 0; st < n; ++st) {
		if (side[st] == -1) {
			q.push(st);
			side[st] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : adj[v]) {
					if (side[u] == -1) {
						side[u] = side[v] ^ 1;
						q.push(u);
					} else {
						is_bipartite &= side[u] != side[v];
					}
				}
			}
		}
	}
	if (!is_bipartite) cout << -1 << endl;
	else {
		vector<int> a, b;
		for (int i = 0; i < n; i ++){
			if (side[i] == 0){
				a.push_back(i);
			}else{
				b.push_back(i);
			}
		}
		cout << a.size() << endl;
		for (auto &x : a) {
			cout << x + 1 << " ";
		}
		cout << endl;
		cout << b.size() << endl;
		for (auto &x : b){
			cout << x + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}
