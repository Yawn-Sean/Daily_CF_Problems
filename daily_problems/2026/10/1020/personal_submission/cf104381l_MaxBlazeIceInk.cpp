#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define int long long
#define INF (int)1e18

int n,m,T,dis[MAXN][MAXN],vis[MAXN][MAXN];
vector< pair<int,int> > E[MAXN];

struct node{
	int u,c,dis;
	inline bool operator <( const node &b ) const{
		return b.dis < dis;
	}
};

signed main(){
	scanf("%lld%lld%lld",&n,&m,&T);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,l; scanf("%lld%lld%lld",&u,&v,&l);
		E[u].emplace_back( make_pair( v , l ) );
		E[v].emplace_back( make_pair( u , l ) );
	}
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 0 ; j <= n ; j ++ ) dis[i][j] = INF,vis[i][j] = 0;
	priority_queue<node> Q;
	Q.push( node{ 1 , 0 , dis[1][0] = 0 } );
	while( !Q.empty() ){
		int u = Q.top().u,c = Q.top().c; Q.pop();
		if( vis[u][c] ) continue;
		vis[u][c] = 1;
		for( pair<int,int> p : E[u] ){
			int v = p.first,w = p.second;
			//什么叫几把 w=0 就不加疲惫度了
			if( dis[v][c + ( w > 0 )] > dis[u][c] + w * c ){
				dis[v][c + ( w > 0 )] = dis[u][c] + w * c;
				if( !vis[v][c + ( w > 0 )] ) Q.push( node{ v , c + ( w > 0 ) , dis[v][c + ( w > 0 )] } );
			}
		}
	}
	int res = INF;
	for( int i = 0 ; i <= n ; i ++ ) res = min( res , dis[T][i] );
	if( res == INF ) res = -1;
	printf("%lld\n",res);
	return 0;
}