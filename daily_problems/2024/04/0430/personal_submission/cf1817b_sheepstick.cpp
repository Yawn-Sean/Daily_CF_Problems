#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> edges(n);
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	vector<int> parent(n, -1), visited(n);
	int st, ed;

	//find any minimal cycle
	auto dfs = [&](auto self, int i, int p, int f) -> bool {
		visited[i] = 1;
		for (auto &nxt : edges[i]){
			if (nxt == p) continue;
			if (nxt == f){
				st = f; 
				ed = i;
				return true;
			}
		}
		for (auto &nxt : edges[i]){
			if (nxt == p) continue;
			if (!visited[nxt]){
				parent[nxt] = i;
				if (self(self, nxt, i, f)) return true;
			}
		}
		return false;
	};

	vector<array<int,2>> res;

	for (int i = 0; i < n; i++){
		if ((int)edges[i].size() >= 4){
			fill(visited.begin(), visited.end(), 0);
			fill(parent.begin(), parent.end(), -1);
			if (dfs(dfs, i, parent[i], i)) {
				vector<int> cnt(n, 0);
				for (int j = ed; j != st; j = parent[j]){
					cnt[j]++;
					res.push_back({j, parent[j]});
				}
				res.push_back({st, ed});
				int val = 0;
				for (auto &nxt : edges[i]){
					if (!cnt[nxt]) {
						res.push_back({st, nxt});
						if (++val == 2) break;
					}
				}
				break;
			}
		}
	}
	if (res.empty()){
		cout << "NO\n";
	}
	else {
		int sz = res.size();
		cout << "YES\n";
		cout << sz << "\n";
		for (int i = 0; i < sz; i++){
			cout << res[i][0] + 1 <<" "<< res[i][1] + 1 << "\n";
		}
	}

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}