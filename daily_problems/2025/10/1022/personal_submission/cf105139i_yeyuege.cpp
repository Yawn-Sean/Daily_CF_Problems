#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define endl "\n"

const int N=2e5+5;

vector<vector<int>>adj(N);
int val[N],son[N],fa[N],dep[N],siz[N],top[N],dfn[N],rnk[N];
int cnt;

void dfs1(int u,int fau){
	son[u]=-1;
	siz[u]=1;
	for(int v:adj[u]){
		if(v==fau)continue;
		dep[v]=dep[u]+1;
		fa[v]=u;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(son[u]==-1||siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}

void dfs2(int u,int fau,int t){
	top[u]=t;
	dfn[u]=++cnt;
	rnk[cnt]=u;
	if(son[u]==-1)return;
	dfs2(son[u],u,t);
	for(int v:adj[u]){
		if(v==fau||v==son[u])continue;
		dfs2(v,u,v);
	}
}

int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[v] ]>dep[top[u]]){
			swap(u,v);
		}
		u=fa[top[u]];
	}
	return dep[u] > dep[v] ? v : u;
}

int dis(int u, int v) {
	int father = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[father] + 1;
}

struct DSU{
	vector<int>f,siz;

	DSU(){}
	DSU(int n){
		init(n);
	}

	void init(int n){
		f.resize(n);
		iota(f.begin(),f.end(),0);
		siz.assign(n,1);
	}

	int find(int x){
		while(x!=f[x]){
			x=f[x]=f[f[x]];
		}
		return x;
	}

	bool same(int x,int y){
		return find(x) == find(y);
	}

	bool merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return false;
		}
		siz[x]+=siz[y];
		f[y]=x;
		return true;
	}

	int size(int x){
		return siz[find(x)];
	}
};

struct DSU1{
	vector<int>f,siz,len;
	vector<pii>point;

	DSU1(){}
	DSU1(int n){
		init(n);
	}

	void init(int n){
		f.resize(n);
		iota(f.begin(),f.end(),0);
		point.resize(n);
		for (int i = 0; i < n; i++) {
			point[i] = {i, i};
		}
		siz.assign(n,1);
		len.assign(n,1);
	}

	int find(int x){
		while(x!=f[x]){
			x=f[x]=f[f[x]];
		}
		return x;
	}

	bool same(int x,int y){
		return find(x) == find(y);
	}

	bool merge(int x,int y){
		int fx = find(x);
		int fy = find(y);
		if(fx == fy){
			return false;
		}

		int lx = point[fx].first, rx = point[fx].second;
		int ly = point[fy].first, ry = point[fy].second;

		if (dis(x, lx) + dis(y, ly) > len[fx]) {
			len[fx] = dis(x, lx) + dis(y, ly);
			point[fx] = {lx, ly};
		}
		if (dis(x, rx) + dis(y, ly) > len[fx]) {
			len[fx] = dis(x, rx) + dis(y, ly);
			point[fx] = {rx, ly};
		}
		if (dis(x, lx) + dis(y, ry) > len[fx]) {
			len[fx] = dis(x, lx) + dis(y, ry);
			point[fx] = {lx, ry};
		}
		if (dis(x, rx) + dis(y, ry) > len[fx]) {
			len[fx] = dis(x, rx) + dis(y, ry);
			point[fx] = {rx, ry};
		}

		if (len[fx] < len[fy]) {
			len[fx] = len[fy];
			point[fx] = point[fy];
		}

		siz[fx]+=siz[fy];
		f[fy]=fx;
		return true;
	}

	int maxlen(int x) {
		x = find(x);
		return len[x];
	}

	int size(int x){
		return siz[find(x)];
	}
};

vector<int> color(N, -1);
int ans[N];

void solve(){
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dep[1] = 1;
	dfs1(1, 1);
	dfs2(1, 1, 1);

	DSU dsu (n + 5);

	vector<pii>tim;
	vector<int>vis(n + 1, 0);

	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		int ru = lca(u, v);
		u = dsu.find(u), v = dsu.find(v);
		while (dep[u] > dep[ru]) {
			vis[u] = 1;
			tim.push_back({i, u});
			dsu.merge(fa[u], u);
			u = dsu.find(u);
		}
		swap(u, v);
		while (dep[u] > dep[ru]) {
			vis[u] = 1;
			tim.push_back({i, u});
			dsu.merge(fa[u], u);
			u = dsu.find(u);
		}
		if (!vis[ru]) {
			vis[ru] = 1;
			dsu.merge(fa[ru], ru);
			tim.push_back({i, ru});
		}
	}

	DSU1 dsu1(n + 5);
	int t0 = 0;
	for (int i = 0; i < tim.size(); i++) {
		auto [t, u] = tim[i];
		while(t0 < t) {
			t0++;
			ans[t0] = max(ans[t0], ans[t0 - 1]);
		}
		color[u] = 1;
		for (int v : adj[u]) {
			if (color[u] == color[v]) {
				dsu1.merge(u, v);
				ans[t] = max(ans[t], dsu1.maxlen(u));
			}
		}
	}
    
    while (t0 <= q) {
        ans[t0] = max(ans[t0], ans[t0 - 1]);
        t0++;
    }

	DSU1 dsu2(n + 5);
	t0 = q;
	int maxn = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			color[i] = 2;
			for (int v : adj[i]) {
				if (color[i] == color[v]) {
					dsu2.merge(i, v);
					ans[t0] = max(ans[t0], dsu2.maxlen(i));
					maxn = max(maxn, dsu2.maxlen(i));
				}
			}
		}
	}

	for (int i = tim.size() - 1; i >= 0; i--) {
		auto [t, u] = tim[i];
		t--;
		while (t0 > t) {
			t0--;
			ans[t0] = max(ans[t0], maxn);
		}
		color[u] = 2;
		for (int v : adj[u]) {
			if (color[u] == color[v]) {
				dsu2.merge(u, v);
				ans[t] = max(ans[t], dsu2.maxlen(u));
				maxn = max(maxn, dsu2.maxlen(u));
			}
		}
	}

	while(t0 > 0) {
		t0--;
		ans[t0] = max(ans[t0], maxn);
	}

	for (int i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}


	for (int i = 1; i <= n; i++) {
		color[i] = -1;
		adj[i].clear();
	}

	for (int i = 0; i <= q; i++) {
		ans[i] = 0;
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
