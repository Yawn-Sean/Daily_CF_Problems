#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,md=1e9+7;
#define int long long
using LL=long long;
struct edge{int u,v;};
vector<edge>e;
vector<int>h[N],g[N];

int dfn[N],low[N],tot;
int stk[N],top;
int scc[N],cnt,siz[N];

void add(int a,int b){
	e.push_back({a,b});
	h[a].push_back(e.size()-1);
}

void tarjan(int u,int in_d){
	dfn[u]=low[u]=++tot;
	stk[++top]=u;
	for(int i:h[u]){
	  int v=e[i].v;
	  if(!dfn[v]){
		tarjan(v,i);
		low[u]=min(low[u],low[v]);	
	  }
	  else if(i!=(in_d^1)){
		low[u]=min(dfn[v],low[u]);
	  }
	}
	if(dfn[u]==low[u]){
		++cnt;int v;
		do{
			v=stk[top--];
			scc[v]=cnt;
			siz[cnt]++;
		}while(v!=u);
	}
}

LL ksm(LL a,LL b){
	LL res=1;
	while(b){
		if(b&1)res=res*a%md;
		a=a*a%md;
		b>>=1;
	}
	return res;
}

unordered_map<int,int>mp[N];
void solve(){
	int n,m;cin>>n>>m;
	vector<pair<int,int>>vv;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		vv.emplace_back(a,b);
		add(a,b);add(b,a);
	}	
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i,1);
	}
	for(auto[u,v]:vv){
		u=scc[u],v=scc[v];
		if(mp[u][v]||u==v)continue;
		mp[u][v]=1;
		//cout<<u<<" "<<v<<"\n";
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>val(n+1);
	for(int i=1;i<=n;i++){
		if(siz[scc[i]]>1){
			val[scc[i]]=1;
		}
	}
	
	vector<int>dep(n+1),len(n+1);
	vector<array<int,22>>f(n+1),p(n+1);
	auto dfs=[&](auto&&dfs,int u,int fa)->void{
		dep[u]=dep[fa]+1;
		len[u]=len[fa]+val[u];
		f[u][0]=fa;
		for(int i=1;i<22;i++){
			f[u][i]=f[f[u][i-1]][i-1];
		}
		for(int v:g[u]){
			if(v==fa)continue;
			dfs(dfs,v,u);
		}
	};
	dfs(dfs,1,0);
	
	auto lca=[&](int u,int v)->int{
		if(dep[u]<dep[v])swap(u,v);
		for(int i=20;i>=0;i--){
			if(dep[f[u][i]]>=dep[v])
				u=f[u][i];
		}
		if(u==v)return v;
		for(int i=20;i>=0;i--){
			if(f[u][i]!=f[v][i]){
				u=f[u][i],v=f[v][i];
			}
		}
		return f[u][0];
	};
	

	int q;cin>>q;
	while(q--){
		int a,b;cin>>a>>b;
		a=scc[a],b=scc[b];
		int fa=lca(a,b);
		// int d1=dep[a]-dep[fa];
		// int d2=dep[b]-dep[fa];
		// int num=p[a][d1]+p[b][d2]-val[fa];
		int num=len[a]+len[b]-len[fa]*2+val[fa];
		cout<<ksm(2,num)<<"\n";
		//cout<<num<<"\n";
	}
	
	
	
	// for(int i=1;i<=cnt;i++){
		// cout<<val[i]<<" ";
	// }
	// cout<<"\n";
// 	
// 	
// 	
// 	
	// for(int i=1;i<=n;i++){
		// cout<<dfn[i]<<" "<<low[i]<<"\n";;
	// }
// 	
	// cout<<"\n";
	// for(int i=1;i<=n;i++){
		// cout<<scc[i]<<" ";
	// }
	// cout<<"\n";
// 	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;

	while(tt--)
		solve();
	return 0;
}
