#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<pii> edges;
	for(int i = 1; i <= m; i ++){
		int a, b;
		cin >> a >> b;
		edges.push_back({a, b});
	}
	int l = 1, r = m;
	auto check = [&](int x)->bool{
		queue<int> q;
		vector<int> deg(n + 1);
		vector<vector<int>> g(n + 1); 
		for(int i = 0; i < x; i ++){
			int a = edges[i].x, b = edges[i].y;
			g[a].push_back(b);
			deg[b] ++;
		}
		for(int i = 1; i <= n; i ++){
			if(!deg[i]) q.push(i);
		}
		while(q.size()){
			if(q.size() > 1) return false;
			auto t = q.front();
			q.pop();
			for(int u: g[t]){
				if(--deg[u] == 0){
					q.push(u);
				}
			}
		}
		return true;
	};
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(check(l)) cout << l;
	else cout << -1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --){
		solve();
	}
}
