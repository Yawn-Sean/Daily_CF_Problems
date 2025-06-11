/*
    Bonelight * v * 
    20240924 I'm Happy, solved 2013 / F2
    Not Coding, No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

class Bin{
	public:
		vector<int> X,sz;
		Bin(){};
		Bin(int n): X(n + 1), sz(n + 1, 1){
			for(int i = 1; i <= n; i ++) X[i] = i;
		};
		int find(int x){
			// cerr << x << endl;
			return X[x] = (X[x] == x? x:find(X[x]));
		}

		void merge(int x, int y){	
			int xx = find(x), yy = find(y);
			if(xx != yy){
				X[xx] = yy;
				sz[yy] += sz[xx];
				sz[xx] = 0;
			}
		}
};

class Edge{
	public:
		int x,y,w;
		bool operator < (Edge b){
			return w < b.w;
		}
};

void solve(){
    int n,m,k,w; cin >> n >> m >> k >> w;
	vector<vector<string>> a(k + 1, vector<string>(n + 1));
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= n; j ++){
			cin >> a[i][j];
		}
	}
	Bin bin(k);
	vector<Edge> edge;
	for(int i = 1; i <= k; i ++){
		edge.push_back({i,0,n * m});
		for(int j = i + 1; j <= k; j ++){
			int t = 0;
			for(int x = 1; x <= n; x ++){
				for(int y = 0; y < m; y ++){
					if(a[i][x][y] != a[j][x][y]) t ++;
				}
			}
			edge.push_back({i,j,t * w});
		}
	}

	sort(begin(edge), end(edge));
	vector<pii> ans_edge;
	int ans = 0;
	for(auto [tx,ty,tw]:edge){
		if(bin.find(tx) == bin.find(ty)) continue;
		bin.merge(tx,ty);
		ans_edge.push_back({tx,ty});
		ans += tw;
	}
	vector<vector<int>> ans_g(k + 1, vector<int>());
	for(auto [tx,ty]:ans_edge){
		ans_g[tx].push_back(ty); 
		ans_g[ty].push_back(tx);
	} 
	vector<int> vis(k + 1);
	
	function<void(int,int)> dfs = [&](int o, int fa){
		for(auto p:ans_g[o]) if(fa != p){
			cout << p << ' ' << o << endl;
			dfs(p,o);
		}
	};
	cout << ans << endl;
	dfs(0,-1);
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
