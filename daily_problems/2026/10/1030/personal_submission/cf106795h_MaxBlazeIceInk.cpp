#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,k,deg[MAXN],dis[MAXN],vis[MAXN];
vector<int> E[MAXN],E2[MAXN];

bitset<8005> G[MAXN];

inline void bfs(){
	for( int i = 1 ; i <= n ; i ++ ) dis[i] = n + 1,vis[i] = 0;
	dis[1] = 0;
	queue<int> Q; Q.push( 1 );
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( int v : E[u] ){
			dis[v] = min( dis[v] , dis[u] + 1 );
			Q.push( v );
		}
	}
}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= n ; i ++ ) G[i].reset();
	for( int i = 1 ; i <= k ; i ++ ){
		int x; scanf("%d",&x);
		G[x][i] = 1;
	}
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v );
		E[v].emplace_back( u );
	}
	bfs();
	for( int i = 1 ; i <= n ; i ++ ){
		for( int v : E[i] ){
			if( dis[v] == dis[i] + 1 ){
				// cerr << i << " " << v << "\n";
				E2[v].emplace_back( i ),deg[i] ++;
			}
		}
	}
	queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) if( !deg[i] ) Q.push( i );
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		for( int v : E2[u] ){
			G[v] |= G[u];
			if( !--deg[v] ) Q.push( v );
		}
	}
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( G[i].count() == k ) ans = max( ans , dis[i] );
		// cerr << G[i].count() << "\n";
	}
	printf("%d\n",ans);
	return 0;
}