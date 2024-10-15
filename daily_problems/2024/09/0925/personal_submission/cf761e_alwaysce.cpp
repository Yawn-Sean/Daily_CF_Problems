#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<int>> path(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	
	for (int i = 0; i < n; i++) {
		if (path[i].size() > 4) {
			cout << "NO\n";
			return 0;
		}
	}
	
	vector<pair<int,int>> pos(n);
	vector<int> used(n);
	
	pos[0] = {0, 0};
	used[0] = 1;
	
	vector<pair<int,int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	vector<array<int, 3>> stk;
	
	stk.push_back({0, -1, 1 << 29});
	
	while (!stk.empty()) {
		auto pr = stk.back();
		stk.pop_back();
		int u = pr[0];
		int nd = pr[1];
		int msk = pr[2];
		
		int cur_d = 0;
		msk >>= 1;
		for (auto& v: path[u]) {
			if (!used[v]) {
				used[v] = 1;
				
				if (cur_d == nd) {
					cur_d++;
				}
				
				int dx = dirs[cur_d].first, dy = dirs[cur_d].second;
				pos[v].first = pos[u].first + dx * msk;
				pos[v].second = pos[u].second + dy * msk;
				
				stk.push_back({v, cur_d ^ 2, msk});
				cur_d++;
			}
		}
	}
	
	cout << "YES\n";
	for (auto& p: pos) {
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}
