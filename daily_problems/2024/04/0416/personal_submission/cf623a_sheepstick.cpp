#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector adj(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		adj[u][v] = adj[v][u] = 1;
 	}
 	int zero = -1;
 	vector<int> state(n, -1);
 	for (int i = 0; i < n; i++){
 		int tot = count(adj[i].begin(), adj[i].end(), 1);
 		if (tot == n - 1) state[i] = 1;
 		else if (zero != -1){
 			if (adj[zero][i]) state[i] = 0;
 			else state[i] = 2;
 		}
 		else {
 			zero = i;
 			state[i] = 0;
 		}
 	}
 	//verify
 	bool ok = true;
 	for (int i = 0; i < n; i++){
 		for (int j = i + 1; j < n; j++){
 			if (adj[i][j]){
 				if (abs(state[i] - state[j]) > 1) ok = false;
 			}
 			else {
 				if (abs(state[i] - state[j]) <= 1) ok = false;
 			}
 		}
 	}
 	if (!ok) {
 		cout << "No\n";
 		return;
 	}
 	cout << "Yes\n";
 	for (int i = 0; i < n; i++){
 		cout << (char)(state[i] + 'a');
 	}
 	cout << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}