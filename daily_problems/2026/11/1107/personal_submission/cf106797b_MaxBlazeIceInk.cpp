#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,k,p[MAXN],maxx[MAXN],at[MAXN];
vector<int> E[MAXN],ans;

void dfs( int x ){
	for( int v : E[x] ){
		dfs( v );
		if( !at[v] )
		maxx[x] = max( maxx[x] , maxx[v] + 1 );
	}
	if( maxx[x] == k - 1 ) ans.emplace_back( x ),at[x] = 1;
}

signed main(){
	scanf("%d%d",&n,&k);
	for( int i = 2 ; i <= n ; i ++ ){
		int x; scanf("%d",&x);
		E[x].emplace_back( i );
	}
	dfs( 1 );
	if( !at[1] ) ans.emplace_back( 1 );
	sort( ans.begin() , ans.end() );
	printf("%d\n",(int)ans.size());
	for( int ele : ans ) printf("%d ",ele);
	return 0;
}