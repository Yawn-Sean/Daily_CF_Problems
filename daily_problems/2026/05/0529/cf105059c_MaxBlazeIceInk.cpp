#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
int n,m,g,col[MAXN];

vector<int> E[MAXN];

bool flag = 1;

void dfs( int x ){
	// if( col[x] ) return;
	for( int v : E[x] ){
		if( col[v] == col[x] && col[v] ) flag = 0;
		else if( !col[v] ) col[v] = 3 - col[x],dfs( v );
	}
}

signed main(){
	scanf("%d%d%d",&n,&m,&g);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	// if( m == 1 ){ printf("%d\n",1); return 0; }
	col[1] = 1,dfs( 1 );
	// for( int i = 1 ; i <=)
	for( int i = 1 ; i <= n ; i ++ )
		for( int j : E[i] ) if( col[i] == col[j] ) flag = 0;
	if( !flag ) puts("0");
	else{
		if( g == 2 ){
			if( col[1] == col[n] ) puts("0");
			else puts("1");
		}
		else{
			if( col[1] == col[n] ) puts("0");
			else puts("0");
		}
	}
	return 0;
}