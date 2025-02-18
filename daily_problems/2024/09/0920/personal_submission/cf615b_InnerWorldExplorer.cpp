#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>());
	vector<int> deg(n);
	int u, v;
	for (int i = 0; i < m; i ++) {
		cin >> u >> v;
		u --;
		v --;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u] ++;
		deg[v] ++;
	}
	long long ans = 0;
	vector<int> d(n, 1);
	for (int i = 0; i < n; i ++){
		for (auto j : g[i]){
			if (j < i)
				d[i] = max(d[i], d[j] + 1);
		}
		ans = max(ans, 1LL * d[i] * deg[i]);
	}
	cout << ans << endl;
	return 0;
}
