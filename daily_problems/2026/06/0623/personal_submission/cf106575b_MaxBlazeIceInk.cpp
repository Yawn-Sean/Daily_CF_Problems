#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 400005
#define INF (int)2e18

int n,m,k,c,f[MAXN],ind[MAXN],cas[MAXN],dis[MAXN],vis[MAXN];
int id[2][MAXN];
vector< pair<int,int> > E[MAXN];

struct node{
	int x,dis;
	inline bool operator <( const node &b )const{
		return b.dis < dis;
	}
};

signed main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&c);
	int cnt = n;
	for( int i = 1 ; i <= k ; i ++ ) scanf("%lld",&ind[i]),cas[ind[i]] = 1,id[0][ind[i]] = ++cnt,id[1][ind[i]] = ++cnt;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&f[i]);
	for( int i = 1 ; i <= k ; i ++ ) E[id[0][ind[i]]].emplace_back( make_pair( id[1][ind[i]] , f[ind[i]] ) );
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		if( cas[u] && cas[v] ) continue;
		if( cas[u] && !cas[v] ){
			E[v].emplace_back( make_pair( id[0][u] , 0 ) );
			E[id[1][u]].emplace_back( make_pair( v , 0 ) );
		}
		else if( cas[v] && !cas[u] ){
			E[u].emplace_back( make_pair( id[0][v] , 0 ) );
			E[id[1][v]].emplace_back( make_pair( u , 0 ) );
		}
		else{
			E[u].emplace_back( make_pair( v , 0 ) );
			E[v].emplace_back( make_pair( u , 0 ) );
		}
	}
	for( int i = 1 ; i <= cnt ; i ++ ) dis[i] = INF,vis[i] = 0;
	priority_queue<node> Q;
	Q.push( node{ 1 , dis[1] = 0 } );
	while( !Q.empty() ){
		int u = Q.top().x; Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( pair<int,int> p : E[u] ){
			int v = p.first,w = p.second;
			if( dis[v] > dis[u] + w ){
				dis[v] = dis[u] + w;
				if( !vis[v] ) Q.push( node{ v , dis[v] } );
			}
		}
	}
	if( dis[n] > c ) dis[n] = -1;
	printf("%lld\n",dis[n]);
	return 0;
}