#include <bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
int n,m,start;
struct Edge{int v;ll w;};
vector <Edge> g[N],G[N];
int dfn[N],low[N],cnt,S[N],tot;
stack <int> st;
ll val[N],dis[N];
bool vis[N];
void Tarjan(int k){
	dfn[k]=low[k]=++cnt;st.push(k);vis[k]=1;
	for(int i(0);i<g[k].size();++i){
		int s(g[k][i].v);
		if(!dfn[s]){
			Tarjan(s);
			low[k]=min(low[k],low[s]);
		}
		else if(vis[s]) low[k]=min(low[k],dfn[s]);
	}
	if(low[k]==dfn[k]){
		int x(-1);++tot;
		while(x^k){
			x=st.top();st.pop();
			S[x]=tot;vis[x]=0;
		}
	}
}
inline ll dfs(int k){
	if(dis[k]) return dis[k];
	for(int i(0);i<G[k].size();++i)
		dis[k]=max(dis[k],dfs(G[k][i].v)+G[k][i].w);
	return dis[k]+=val[k];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i(1);i<=m;++i){
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u].push_back((Edge){v,w});
	}
	for(int i(1);i<=n;++i) if(!dfn[i]){cnt=0;Tarjan(i);}
	for(int u(1);u<=n;++u)
		for(int i(0);i<g[u].size();++i){
			int v(g[u][i].v);
			if(S[u]==S[v]){
				ll t(sqrt(2*g[u][i].w+0.25)-0.5);
				val[S[u]]+=(t+1)*g[u][i].w-t*(t+1)*(t+2)/6;
			}
			else G[S[u]].push_back((Edge){S[v],g[u][i].w});
		}
	scanf("%d",&start);
	printf("%lld\n",dfs(S[start]));
	return 0;
}
