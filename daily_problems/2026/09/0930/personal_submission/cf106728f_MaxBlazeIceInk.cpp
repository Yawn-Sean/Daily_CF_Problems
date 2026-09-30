#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define int long long
#define INF (int)1e18

int n,m,t[MAXN],h[MAXN],f[MAXN],vis[MAXN];
vector< pair<int,int> > E[MAXN];

//f[u]：想要从 u 安全到达点 1，你最晚什么时候需要到

signed main(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%lld%lld%lld%lld",&u,&v,&t[i],&h[i]);
		E[u].emplace_back( make_pair( v , i ) );
		E[v].emplace_back( make_pair( u , i ) );
	}
	for( int i = 1 ; i <= n ; i ++ ) f[i] = -INF;
	f[1] = INF;
	priority_queue< pair<int,int> > Q;
	Q.push( make_pair( f[1] , 1 ) );
	while( !Q.empty() ){
		int u = Q.top().second; Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( pair<int,int> p : E[u] ){
			int v = p.first,id = p.second;
			f[v] = max( f[v] , min( h[id] - t[id] , f[u] - t[id] ) );
			if( !vis[v] ) Q.push( make_pair( f[v] , v ) );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		if( f[i] >= 0 ) printf("1");
		else printf("0");
	}
	return 0;
}