#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,k,f[MAXN],deg[MAXN];
vector<int> E[MAXN];
map<int,int> bann[MAXN];

int find( int x , int st ){
	while( bann[x].count( st ) ) st ++;
	return st;
}

signed main(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),deg[v] ++;
	}
	scanf("%d",&k);
	for( int i = 1 ; i <= k ; i ++ ){
		int j,x; scanf("%d%d",&j,&x);
		bann[x][j] = 1;
	}
	queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) if( !deg[i] ) Q.push( i ),f[i] = 1;
	int ans = 0;
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		f[u] = find( u , f[u] );
		ans = max( ans , f[u] );
		for( int v : E[u] ){
			f[v] = max( f[v] , f[u] + 1 );
			if( !--deg[v] ) Q.push( v );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) if( deg[i] ){ puts("-1"); return 0; }
	printf("%d\n",ans);
	return 0;
}