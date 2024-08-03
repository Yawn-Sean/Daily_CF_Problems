#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<array<int,2>>> adj(n);
    for (int i = 0; i < n - 1; i++){
    	int u, v, w; cin >> u >> v >> w;
    	u--; v--;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    vector<vector<array<int,2>>> elves(n);
    for (int i = 0; i < m; i++){
    	int u, v, w; cin >> u >> v >> w;
    	u--; v--;
    	elves[u].push_back({v, w});
    	elves[v].push_back({u, w});
    }
    vector<int> par(n, -1);

    auto dfs = [&](auto self, int u, int parity) -> bool {
    	if (par[u] >= 0){
    		if (par[u] != parity) return false;
    		return true;
    	}
    	par[u] = parity;
    	for (auto [v, w] : adj[u]){
    		if (w != -1){
    			if (!self(self, v, parity ^ (__builtin_popcount(w) & 1))) return false;
    		}
    	}
    	for (auto &[v, w] : elves[u]){
    		if (!self(self, v, parity ^ (__builtin_popcount(w) & 1))) return false;
    	}
    	return true;
    };
    
    for (int i = 0; i < n; i++) if (par[i] == -1){
    	if (!dfs(dfs, i, 0)) {
    		cout << "NO\n";
    		return;
    	}
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++){
    	for (auto [v, w] : adj[i]){
    		if (i > v) continue;
    		int cur = (w >= 0 ? w : (par[i] ^ par[v]));
    		cout << i + 1 <<" "<< (v + 1) << " "<< cur << "\n";
    	}
    }
    

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}