#include<bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define MAXK 11

int n,m,a,b,k,dis[2][2][MAXN][MAXK],vis[MAXN][MAXK],g[2][MAXN];
vector< pair<int,int> > E[2][MAXN];

struct node{
	int x,j,dis;
	inline bool operator <( const node &b ) const{
		return b.dis < dis;
	}
};

inline void dijkstra( int s , int op , int rev ){
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 0 ; j <= k ; j ++ ) dis[op][rev][i][j] = (int)1e9,vis[i][j] = 0;
	priority_queue<node> Q;
	Q.push( node{ s , 0 , dis[op][rev][s][0] = 0 } );
	while( !Q.empty() ){
		int u = Q.top().x,j = Q.top().j; Q.pop();
		if( vis[u][j] ) continue;
		vis[u][j] = 1;
		for( pair<int,int> p : E[rev][u] ){
			int v = p.first,w = p.second;
			if( dis[op][rev][v][j] > dis[op][rev][u][j] + w ){
				dis[op][rev][v][j] = dis[op][rev][u][j] + w;
				Q.push( node{ v , j , dis[op][rev][v][j] } );
			}
			if( j < k && dis[op][rev][v][j + 1] > dis[op][rev][u][j] ){
				dis[op][rev][v][j + 1] = dis[op][rev][u][j];
				Q.push( node{ v , j + 1 , dis[op][rev][v][j + 1] } );
			}
		}
	}
}

signed main(){
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&k); a ++,b ++;
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,w; scanf("%d%d%d",&u,&v,&w); u ++,v ++;
		E[0][u].emplace_back( make_pair( v , w ) );
		E[1][v].emplace_back( make_pair( u , w ) );
	}
	dijkstra( a , 0 , 0 ),dijkstra( a , 0 , 1 );
	dijkstra( b , 1 , 0 ),dijkstra( b , 1 , 1 );
	for( int i = 1 ; i <= n ; i ++ ){
		if( i == a || i == b ) continue;
		int ans = (int)1e9;
		for( int j = 0 ; j <= k ; j ++ ){
			for( int t = 0 ; j + t <= k ; t ++ ){
				int res = dis[0][0][i][j] + dis[0][1][i][t];
				ans = min( ans , res );
			}
		}
		g[0][i] = ans;
	}
	int Ans = (int)1e9,id = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( i == a || i == b ) continue;
		int ans = (int)1e9;
		for( int j = 0 ; j <= k ; j ++ ){
			for( int t = 0 ; j + t <= k ; t ++ ){
				int res = dis[1][0][i][j] + dis[1][1][i][t];
				ans = min( ans , res );
			}
		}
		g[1][i] = ans;
		if( g[0][i] + g[1][i] < Ans ) Ans = g[0][i] + g[1][i],id = i;
	}
	// for( int i = 1 ; i <= n
	if( Ans == (int)1e9 ){ puts(">:("); return 0; }
	printf("%d %d",id - 1,Ans);
	return 0;
}