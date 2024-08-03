#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 2E5 + 10;
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<array<int,2>>> adj(n);
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		char x; cin >> x;
		int color = (x == 'B');
		adj[u].push_back({v, color});
		adj[v].push_back({u, color});
	}

	int res = INT_MAX;
	vector<vector<int>> ops(2);
	int best = -1;

	auto gao = [&](int goal) -> void {
		vector<int> stk, color(n, -1);
		vector<vector<int>> belong(M);
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (color[i] == -1){
				color[i] = cnt;
				belong[cnt].push_back(i);
				cnt += 2;
				stk.push_back(i);
				while(!stk.empty()){
					//cerr << stk.back() << "---\n";
					auto u = stk.back(); stk.pop_back();
					for (auto &[v, c] : adj[u]){
						if (color[v] != -1) {
							if (((color[v] ^ color[u] ^ c) != goal)) return;
						}
						else {
							color[v] = (goal ^ c ^ color[u]);
							belong[color[v]].push_back(v);
							stk.push_back(v);
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < cnt; i += 2){
			if ((int) belong[i].size() <= (int) belong[i + 1].size()){
				ans += (int) belong[i].size();
				ops[goal].insert(ops[goal].end(), belong[i].begin(), belong[i].end());
			}
			else {
				ans += (int) belong[i + 1].size();
				ops[goal].insert(ops[goal].end(), belong[i + 1].begin(), belong[i + 1].end());
			}
		}
		if (ans < res){
			best = goal;
			res = ans;
		}
	};
	gao(0);
	gao(1);
	if (res == INT_MAX) {
		cout << "-1\n";
		return;
	}
	else cout << res << "\n";
	for (auto v : ops[best]){
		cout << v + 1 <<" ";
	}
	cout << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}