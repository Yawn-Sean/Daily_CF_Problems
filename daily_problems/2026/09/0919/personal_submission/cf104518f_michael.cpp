#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<pair<int,int>,ll> edge;

const int MAX = 3e5 + 5;
vector<int> father(MAX);

void init(int n){
	for(int i = 1; i <= n; ++i){
		father[i] = i;
	}
}

int find(int x){
	if(father[x] != x){
		father[x] = find(father[x]);
	}
	return father[x];
}

void uni(int x,int y){
	father[find(x)] = find(y);
}

bool isSame(int x,int y){
	return find(x) == find(y);
}

void solve(){
	int n,m;
	cin >> n >> m;
	init(n);
	vector<edge> edges(m);
	for(auto &[pos,cost] : edges) cin >> pos.first >> pos.second >> cost;
	sort(edges.begin(),edges.end(), [&](edge e1,edge e2){return e1.second < e2.second;});
	ll ans = 0;
	vector<vector<int>> path(n + 1);

	for(auto &[pos,cost] : edges){
		auto[x,y] = pos;
		if(!isSame(x,y)){
			uni(x,y);
			ans += cost;
			path[x].emplace_back(y);
			path[y].emplace_back(x);
		}
	}

	cout << ans * 2 << '\n';
	vector<int> order;
	auto dfs = [&](auto &self,int u,int p)-> void{
		order.emplace_back(u);
		for(auto &v : path[u]){
			if(v != p){
				self(self,v,u);
				order.emplace_back(u);
			}
		}
	};
	dfs(dfs,1,0);
	cout << 2 * n - 1 << '\n';
	for(int i = 0; i < 2 * n - 1; ++i){
		cout << order[i] << " ";
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}