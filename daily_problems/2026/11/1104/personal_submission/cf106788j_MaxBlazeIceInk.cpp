#include<bits/stdc++.h>
using namespace std;

#define MAXN 3005
#define INF (int)1e9

int n,m,k,wss[MAXN],wcnt,dis[MAXN],vis[MAXN];
vector< pair<int,int> > E[MAXN];

struct node{
	int x,dis;
	inline bool operator <( const node &b ) const{
		return b.dis < dis;
	}
};


inline int dijkstra( int w0 ){
	int c = 0;
	for( int i = 1 ; i <= n ; i ++ ) dis[i] = INF,vis[i] = 0;
	priority_queue<node> Q;
	Q.push( node{ 1 , dis[1] = 0 } );
	while( !Q.empty() ){
		int u = Q.top().x; Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( auto [v,w] : E[u] ){
			int nw = w <= w0 ? w0 : w;
			if( dis[v] > dis[u] + nw ){
				dis[v] = dis[u] + nw;
				Q.push( node{ v , dis[v] } );
			}
		}
	}
	return max( 0 , dis[n] - w0 * k ); 
}
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		u ++,v ++; wss[++wcnt] = w;
		E[u].emplace_back( make_pair( v , w ) );	
	}
	wss[++wcnt] = (int)1e5 + 1;
	sort( wss + 1 , wss + wcnt + 1 );
	wcnt = unique( wss + 1 , wss + wcnt + 1 ) - ( wss + 1 );
	int Ans = INF;
	for( int i = 1 ; i <= wcnt ; i ++ ) Ans = min( Ans , dijkstra( wss[i] ) );
	printf("%d\n",Ans);
	return 0;
}