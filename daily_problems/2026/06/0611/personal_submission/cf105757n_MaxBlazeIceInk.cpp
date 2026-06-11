#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
int n,deg[MAXN],dfn[MAXN],ed[MAXN],idx,ans[MAXN],nea[MAXN];
vector<int> E[MAXN];

void init( int x , int fa , int rt ){
	nea[x] = rt;
	dfn[x] = ++idx;
	for( int v : E[x] ){
		if( v == fa ) continue;
		init( v , x , rt );
	}
	ed[x] = idx;
}

inline int In( int x , int v ){ return dfn[v] >= dfn[x] && dfn[v] <= ed[x]; }

inline void clear(){
	for( int i = 0 ; i < n ; i ++ ) E[i].clear(),deg[i] = dfn[i] = ed[i] = nea[i] = 0;
	for( int i = 1 ; i <= n ; i ++ ) ans[i] = 0;
	idx = 0;
}

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
		deg[u] ++,deg[v] ++;
	}
	for( int v : E[0] ) init( v , 0 , v );
	int p1 = 0,p2 = 0,mex = 1;
	while( mex < n ){
		if( !p1 ) p1 = mex;
		else{
			if( In( p1 , mex ) ) p1 = mex;
			else if( !In( mex , p1 ) ){
				if( nea[p1] == nea[mex] ) break;
				if( !p2 ) p2 = mex;
				else if( In( p2 , mex ) ) p2 = mex;
				else if( !In( mex , p2 ) ){
					break;
				}
			}
		}
		mex ++;
	}
	ans[2] = mex;
	for( int i = 3 ; i <= n ; i ++ ) ans[i] = deg[0] >= i - 1; 
	for( int i = 2 ; i <= n ; i ++ ) printf("%d ",ans[i]);
	puts("");
	clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}