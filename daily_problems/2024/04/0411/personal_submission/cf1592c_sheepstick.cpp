#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);

    int g = 0;
    for (auto &ai : a){
    	cin >> ai;
    	g = g ^ ai;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
    	int u, v; cin >> u >> v;
    	u--; v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    if (g == 0){
    	cout << "YES\n";
    	return;
    }
    if (k == 2){
    	cout << "NO\n";
    	return;
    }

    bool found = false;
    auto dfs = [&](auto self, int u, int p) -> pair<int,int> {
    	int cut = 0, val = a[u];
    	for (auto &v : adj[u]) if (v != p){
    		auto x = self(self, v, u);
    		cut += x.first;
    		val ^= x.second;
    	}
    	if (cut >= 2) found = true;
    	else if (cut == 1){
    		if (val == 0) found = true;
    	}
    	else {
    		if (val == g) cut = 1;
    	}
    	return {cut, val};
    };
    dfs(dfs, 0, -1);


    cout << (found ? "YES\n" : "NO\n");


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