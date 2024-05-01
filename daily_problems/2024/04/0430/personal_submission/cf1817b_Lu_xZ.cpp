#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n + 1);
	
	for(int i = 1; i <= m; ++ i) {
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	auto bfs = [&](int cur) -> bool {
		if(g[cur].size() < 4) return 0;
		
		vector<int> fa(n + 1, 0), anc(n + 1, 0);
		vector<int> inl(n + 1, 0);
		vector<pair<int, int>> loop;
		
		queue<int> q;
		fa[cur] = -1;
		for(auto x : g[cur]) {
			q.push(anc[x] = x);
			fa[x] = cur;
		}
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int y : g[x]) {
				if(fa[y]) {
					if(y == cur || anc[y] == anc[x]) continue;
					loop.push_back({x, y});
					
					while(x != cur) {
						loop.push_back({x, fa[x]});
						inl[x] = 1;
						x = fa[x];
					}
					while(y != cur) {
						loop.push_back({y, fa[y]});
						inl[y] = 1;
						y = fa[y];
					}
					
					int cnt = 0;
					
					for(int _ : g[cur]) {		// bfs不会出现4个点都在环上
						if(inl[_] == 0) {
							loop.push_back({_, cur});
							if(++ cnt == 2) break;
						}
					}
					
					cout << "YES\n";
					cout << loop.size() << '\n';
					
					for(auto [u, v] : loop) {
						cout << u << ' ' << v << '\n';
					}
					
					return 1;
				}
				else {
					fa[y] = x;
					anc[y] = anc[x];
					q.push(y);
				}
			}
		}
		cout << '\n';
		return 0;
	};
	
	for(int i = 1; i <= n; ++ i) {
		if(bfs(i)) return;
	}
	cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	
	while(T --) {
		solve();
	}
	return 0;
}
