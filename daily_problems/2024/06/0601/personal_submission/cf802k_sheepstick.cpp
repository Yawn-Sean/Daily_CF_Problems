#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<array<int,2>>> adj(n);
	for (int i = 0; i < n - 1; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	//f: i to subtree of i and come back
	// f_u = sum of top (k - 1) value of (f_v + w_{u, v})

	// g: i to subtree of i without requiring coming back
	// enumerate last entering subtree v_{last}, should be top (k - 1) (f_v + w_{u, v}) for all (v != v_last) + g_v_last + w_{u, vlast};
	vector<i64> f(n), g(n);

	auto dfs = [&](auto self, int u, int p) -> void {
		for (auto &[v, w] : adj[u]) if (v != p){
			self(self, v, u);
		}
		if (k == 1){
			f[u] = 0;
			for (auto &[v, w] : adj[u]) if (v != p){
				g[u] = max(g[u], w + g[v]);
			}
			return;
		}

		if ((int) adj[u].size() <= k){
			for (auto &[v, w] : adj[u]) if (v != p){
				f[u] += f[v] + w;
			}
			for (auto &[v, w] : adj[u]) if (v != p){
				g[u] = max(g[u], f[u] - f[v] + g[v]);
			}
		}
		else {
			vector<i64> tmp;
			for (auto &[v, w] : adj[u]) if (v != p){
				tmp.push_back({f[v] + w});
			}
			//partial_sort(tmp.rbegin(), tmp.rbegin() + k, tmp.rend());
			partial_sort(tmp.begin(), tmp.begin() + k, tmp.end(), greater<int>());
			f[u] = accumulate(tmp.begin(), tmp.begin() + k - 1, 0LL);
			for (auto &[v, w] : adj[u]) if (v != p){
				i64 res = f[u] + g[v] + w;
				if (f[v] + w >= tmp[k - 2]) res += tmp[k - 1] - f[v] - w;
				g[u] = max(g[u], res);
			}
		}
	};
	dfs(dfs, 0, -1);
	cout << g[0] << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}