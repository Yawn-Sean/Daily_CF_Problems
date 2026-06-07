#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 250005

int n,q,Fa[MAXN],vis[MAXN];
vector<int> E[MAXN];

int app[MAXN],f[MAXN],siz[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

void dfs( int x , int fa ){
	Fa[x] = fa;
	for( int v : E[x] ){
		if( v == fa ) continue;
		dfs( v , x );
	}
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	dfs( 1 , 0 );
	scanf("%lld",&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int k; scanf("%lld",&k);
		vector<int> R;
		for( int j = 1 ; j <= k ; j ++ ){
			int x; scanf("%lld",&x);
			vis[x] = j,R.emplace_back( x );
		}
		for( int j = 1 ; j <= k ; j ++ ) f[j] = j,siz[j] = 1;
		for( int ele : R ){
			if( vis[Fa[ele]] ){
				siz[find( vis[Fa[ele]] )] += siz[find( vis[ele] )];
				f[find(vis[ ele ])] = find( vis[Fa[ele]] );
			}
		}
		int res = 0;
		for( int j = 1 ; j <= k ; j ++ )
			if( find( j ) == j ) res += siz[j] * ( siz[j] - 1 ) / 2;
		printf("%lld\n",res);
		for( int ele : R ) vis[ele] = 0,siz[ele] = f[ele] = 0;
	}
	return 0;
}