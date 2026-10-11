#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005

int n,m,k,d[MAXN],vis[MAXN],f[MAXN],c[MAXN];

vector<int> E[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

vector< pair<int,int> > ans;
void dfs( int x , int fa ){
	vis[x] = 1;
	for( int v : E[x] ){
		if( v == fa ) continue;
		if( !vis[v] ) dfs( v , x );
		if( d[v] ) ans.emplace_back( make_pair( v , x ) ),d[v] ^= 1,d[x] ^= 1;
	}
}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		d[u] ^= 1,d[v] ^= 1;
	}
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i;
	for( int i = 1 ; i <= k ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
		if( find( u ) != find( v ) )
			f[find( u )] = find( v );
	}
	for( int i = 1 ; i <= n ; i ++ ) c[find( i )] ^= d[i];
	for( int i = 1 ; i <= n ; i ++ ){
		if( find( i ) != i ) continue;
		if( c[i] ){ puts("NO"); return 0; }
		dfs( i , 0 );
	}
	for( int i = 1 ; i <= n ; i ++ ) if( d[i] ){ puts("NO"); return 0; }
	puts("YES");
	printf("%d\n",ans.size());
	for( auto &[u,v] : ans ) printf("%d %d\n",u,v);
	return 0;
}