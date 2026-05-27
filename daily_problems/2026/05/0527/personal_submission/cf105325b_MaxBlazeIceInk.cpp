#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define INF (int)2e9

int n,m,U[MAXN],V[MAXN],W[MAXN],dis[MAXN * MAXN],vis[MAXN * MAXN],id[MAXN][MAXN];
int refe[MAXN * MAXN],ans[MAXN];

vector< pair<int,int> > E[MAXN * MAXN];

struct node{
	int x,dis;
	inline bool operator <( const node &b )const{
		return b.dis < dis;
	}
};

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i ++ )
		scanf("%d%d%d",&U[i],&V[i],&W[i]),U[i] ++,V[i] ++;
	int cnt = 0;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 0 ; j <= n ; j ++ ){
			id[i][j] = ++cnt;
			dis[id[i][j]] = INF,vis[id[i][j]] = 0;
			refe[id[i][j]] = i,ans[i] = INF;
		}
	for( int i = 1 ; i <= m ; i ++ )
		for( int j = n ; j >= 1 ; j -- )
			E[id[U[i]][j]].emplace_back( id[V[i]][j - 1] , W[i] * j );
	priority_queue<node> Q;
	for( int i = 0 ; i <= n ; i ++ ) dis[id[1][i]] = 0,Q.push( node{ id[1][i] , dis[id[1][i]] = 0 } );
	while( !Q.empty() ){
		int u = Q.top().x; Q.pop();
		ans[refe[u]] = min( ans[refe[u]] , dis[u] );
		if( vis[u] ) continue;
		for( pair<int,int> p : E[u] ){
			int v = p.first,w = p.second;
			if( dis[v] > dis[u] + w ){
				dis[v] = dis[u] + w;
				if( !vis[v] ) Q.push( node{ v , dis[v] } );
			}
		}
	}
	for( int i = 2 ; i <= n ; i ++ ){
		if( ans[i] == INF ) ans[i] = -1;
		printf("%d ",ans[i]);
	}
	puts("");
	for( int i = 1 ; i <= cnt ; i ++ ) E[i].clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}