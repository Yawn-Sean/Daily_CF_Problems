#include<bits/stdc++.h>
using namespace std;

#define MAXN 5005

int n,m,dis[MAXN],vis[MAXN],f[MAXN];
vector< pair<int,int> > E[MAXN];

inline int bfs( int x ){
	for( int i = 1 ; i <= n ; i ++ ) vis[i] = 0,dis[i] = n + 1;
	deque<int> Q; Q.push_front( 1 ),dis[1] = 0;
	while( !Q.empty() ){
		int u = Q.front(); Q.pop_front();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( pair<int,int> p : E[u] ){
			int v = p.first;
			int w = p.second >= x;
			if( vis[v] ) continue;
			if( !w ) dis[v] = min( dis[v] , dis[u] ),Q.push_front( v );
			else{
				dis[v] = min( dis[v] , dis[u] + 1 ),Q.push_back( v );
			}
		}
	}
	return dis[n];
}

signed main(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( make_pair( v , i ) );
		E[v].emplace_back( make_pair( u , i ) );
	}
	for( int i = 1 ; i <= m ; i ++ ) f[i] = bfs( i );
	for( int i = 1 ; i <= m ; i ++ ){
		double ans = n + 1;
		for( int j = 1 ; j <= i ; j ++ ){
			ans = min( ans , 1.0 * f[j] / ( i - j + 1 ) );
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}