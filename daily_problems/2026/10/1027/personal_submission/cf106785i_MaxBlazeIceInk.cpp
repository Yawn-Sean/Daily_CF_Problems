#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,k,dep[MAXN],Fa[MAXN];
vector<int> E[MAXN];

void dfs( int x , int fa ){
	dep[x] = dep[fa] + 1,Fa[x] = fa;
	for( int v : E[x] ) if( v != fa ) dfs( v , x );
}

inline void clear(){
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear(),dep[i] = Fa[i] = 0;
}

inline void solve(){
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	dfs( 1 , 0 );
	int S = 0;
	for( int i = 1 ; i <= n ; i ++ ) if( dep[i] >= dep[S] ) S = i;
	dfs( S , 0 );
	int T = 0;
	for( int i = 1 ; i <= n ; i ++ ) if( dep[i] >= dep[T] ) T = i;
	if( dep[T] % 2 ){
		int len = dep[T] / 2;
		for( int i = 1 ; i <= len ; i ++ ) T = Fa[T]; 
		if( k == T ){ puts("Bob"); clear(); return; }
	}
	puts("Alice");
	clear();
	return;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}