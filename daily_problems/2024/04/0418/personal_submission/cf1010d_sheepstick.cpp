#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<string> s(n + 1);

	vector<int> vals(n + 1);
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		if (s[i] == "IN"){
			int x; cin >> x;
			vals[i] = x;
		}
		else if (s[i] == "NOT"){
			int x; cin >> x;
			adj[i].push_back(x);
		}
		else {
			int x, y; cin >> x >> y;
			adj[i].push_back(x);
			adj[i].push_back(y);
		}
	}

	auto dfs1 = [&](auto self, int u) -> void {
		for (auto v : adj[u]){
			self(self, v);
		}
		if (s[u] == "IN") return;
		else if (s[u] == "NOT") vals[u] = !vals[adj[u][0]];
		else if (s[u] == "AND") vals[u] = vals[adj[u][0]] & vals[adj[u][1]];
		else if (s[u] == "OR") vals[u] = vals[adj[u][0]] | vals[adj[u][1]];
		else vals[u] = vals[adj[u][0]] ^ vals[adj[u][1]];
	};
	dfs1(dfs1, 1);

	//if we alter current value, whether the final output will be flipped. 
	vector<int> flip(n + 1, 0);
	flip[1] = 1;

	auto dfs2 = [&](auto self, int u) -> void {
		if (!flip[u] || s[u] == "IN") return;
		if (s[u] == "NOT"){
			flip[adj[u][0]] = 1;
		}
		else if (s[u] == "AND"){
			for (int i = 0; i < 2; i++){
				int tmp = (vals[adj[u][i]] ^ 1) & (vals[adj[u][1 ^ i]]);
				if (tmp != vals[u]) flip[adj[u][i]] = 1;
			}
		}
		else if (s[u] == "OR"){
			for (int i = 0; i < 2; i++){
				int tmp = (vals[adj[u][i]] ^ 1) | (vals[adj[u][1 ^ i]]);
				if (tmp != vals[u]) flip[adj[u][i]] = 1;
			}
		}
		else {
			//xor, always flip
			flip[adj[u][0]] = flip[adj[u][1]] = 1;
		}
		for (auto v : adj[u]){
			self(self, v);
		}
	};
	dfs2(dfs2, 1);

	for (int i = 1; i <= n; i++) if (s[i] == "IN"){
		cout << (vals[1] ^ flip[i]);
	}
	cout << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}