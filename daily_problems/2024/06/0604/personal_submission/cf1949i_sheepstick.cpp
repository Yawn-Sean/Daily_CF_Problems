#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 1 << 30;

void solve() {
    int n; cin >> n;
    vector<array<i64,3>> a(n);
    for (int i = 0; i < n; i++){
    	cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    auto tangent = [&](int i, int j) -> bool {
    	i64 d = (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]);
    	if (d == (a[i][2] + a[j][2]) * (a[i][2] + a[j][2])) return true;
    	return false;
    };
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < i + 1; j++){
    		if (tangent(i, j)){
    			adj[i].push_back(j);
    			adj[j].push_back(i);
    		}
    	}
    }

    vector<int> delta(n, 0), visited(n, 0);
    bool ok = true;
    i64 tot = 0;

    auto dfs = [&](auto self, int u) -> void {
    	visited[u] = 1;
    	for (auto v : adj[u]){
    		if (!visited[v]){
    			delta[v] = -delta[u];
    			tot -= delta[u];
    			self(self, v);
    		}
    		else {
    			if (delta[v] + delta[u] != 0) ok = false;
    		} 
    	}
    };
    for (int i = 0; i < n; i++){
    	if (!visited[i]){
    		tot = 1;
    		ok = true;
    		delta[i] = 1;
    		dfs(dfs, i);
    		if (!ok) continue;
    		else if (tot != 0){
    			cout << "YES\n";
    			return;
    		}
    	}
    }
    cout << "NO\n";


    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}