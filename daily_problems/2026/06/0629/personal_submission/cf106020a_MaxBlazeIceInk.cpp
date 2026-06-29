#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,nea[MAXN][3],cnt[MAXN],vis[MAXN];
vector<int> E[MAXN];

priority_queue< int , vector<int> , greater<int> > Q;

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	for( int i = 1 ; i <= n ; i ++ ) Q.push( i );
	while( !Q.empty() ){
		int u = abs( Q.top() ); Q.pop();
		if( vis[u] ) continue;
		//填不冲突的最小点
		if( !nea[u][0] ) vis[u] = 1;
		else if( !nea[u][1] ) vis[u] = 2;
		else vis[u] = 3;
		for( int v : E[u] ){
			if( !nea[v][vis[u] - 1] ) cnt[v] ++,nea[v][vis[u] - 1] = 1;
			if( !vis[v] && cnt[v] >= 2 ) Q.push( -v );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%c",(char)( vis[i] + 'a' - 1 ));
	return 0;
}