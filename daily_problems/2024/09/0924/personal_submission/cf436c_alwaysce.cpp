#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	
	vector<vector<string>> mat(k, vector<string>(n));
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	
	vector<int> us, vs, ws;
	for (int i = 0; i < k; i++) {
		us.push_back(i);
		vs.push_back(k);
		ws.push_back(n * m);
		
		for (int j = 0; j < i; j++) {
			int co = 0;
			
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					if (mat[i][x][y] != mat[j][x][y]) {
						co += w;
					}
				}
			}
			
			us.push_back(i);
			vs.push_back(j);
			ws.push_back(co);
		}
	}
	
	int num_e = ws.size();
	vector<int> order(num_e);
	
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return ws[i] < ws[j];
	});
	
	
	DSU d(k + 1);
	i64 ans = 0;
	vector<vector<int>> path(k + 1);
	
	for (auto& idx: order) {
		if (d.merge(us[idx], vs[idx])) {
			ans += ws[idx];
			path[us[idx]].push_back(vs[idx]);
			path[vs[idx]].push_back(us[idx]);
		}
	}
	cout << ans << '\n';
	
	vector<pair<int,int>> stk;
	stk.push_back({k, -1});
    
    while (!stk.empty()) {
    	auto pr = stk.back();
    	stk.pop_back();
    	int u = pr.first, p = pr.second;
    	
    	for (auto& v: path[u]) {
    		if (v != p) {
    			cout << v + 1 << ' ' << (u < k ? u + 1: 0) << '\n';
    			stk.push_back({v, u});
    		}
    	}
    }
    
    return 0;
}
