#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define INF (int)1e9

int n,m,a,b,dis[MAXN],dis2[MAXN],vis[MAXN],vis2[MAXN];
vector<int> E[MAXN];

struct node{
	int x,dis;
	inline bool operator <( const node &b ) const{
		return b.dis < dis;
	}
};

inline void solve(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	for( int i = 1 ; i <= n ; i ++ ) dis[i] = dis2[i] = INF,vis[i] = vis2[i] = 0;
	priority_queue<node> Q;
	Q.push( node{ b , dis2[b] = 0 } );
	while( !Q.empty() ){
		int u = Q.top().x; Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( int v : E[u] ){
			if( dis[v] >= dis2[u] + 1 ){
				dis2[v] = dis[v],dis[v] = dis2[u] + 1;
				Q.push( node{ v , dis2[v] } );
			}
			else if( dis2[v] >= dis2[u] + 1 ){
				dis2[v] = dis2[u] + 1;
				Q.push( node{ v , dis2[v] } );
			}
		}
	}
	// for( int i = 1 ; i <= n ; i ++ )cerr << i << " " << dis[i] << " " << dis2[i] << "\n";
	int ans = dis2[a]; if( ans == INF ) ans = -1;
	printf("%d\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) dis[i] = dis2[i] = vis[i] = vis2[i] = 0,E[i].clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}