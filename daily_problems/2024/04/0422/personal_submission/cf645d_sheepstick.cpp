#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<array<int,2>> edges(m);
	for (int i = 0; i < m; i++){
		cin >> edges[i][0] >> edges[i][1];
		edges[i][0]--;
		edges[i][1]--;
	}

	auto check = [&](int k) -> bool {
		vector<vector<int>> adj(n);
		vector<int> indeg(n, 0);
		for (int i = 0; i < k; i++){
			adj[edges[i][0]].push_back(edges[i][1]);
			indeg[edges[i][1]]++;
		}

		queue<int> q;
		for (int i = 0; i < n; i++){
			if (indeg[i] == 0) q.push(i);
		}
		while(!q.empty()){
			int sz = q.size();
			if (sz > 1) return false;

			while(sz--){
				auto u = q.front(); q.pop();
				for (auto &v : adj[u]){
					if (--indeg[v] == 0) q.push(v);
				}
			}
		}
		return true;
	};

	int l = 1, r = m + 1;
	while(l < r){
		int mid = (l + r) / 2;
		if (check(mid)){
			r = mid;
		}
		else l = mid + 1;
	}
	cout << (l == m + 1 ? -1 : l) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}