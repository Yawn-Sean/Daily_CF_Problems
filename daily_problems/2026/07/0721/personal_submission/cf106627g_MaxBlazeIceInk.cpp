#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 500005
#define mod 998244353

int n,m,f[MAXN],p2[MAXN],ans[MAXN];

vector< pair<int,int> > E[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

void dfs( int x , int fa ){
	for( pair<int,int> p : E[x] ){
		int v = p.first; if( v == fa ) continue;
		ans[v] = ( ans[x] + p.second ) % mod;
		dfs( v , x );
	}
}

inline void solve(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i;
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		if( find( u ) != find( v ) ){
			f[find( u )] = find( v );
			E[u].emplace_back( make_pair( v , p2[i - 1] ) );
			E[v].emplace_back( make_pair( u , p2[i - 1] ) );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) ans[i] = -1; ans[1] = 0;
	dfs( 1 , 0 );
	for( int i = 2 ; i <= n ; i ++ ) printf("%lld ",ans[i]); puts("");
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear(),ans[i] = 0;
}

signed main(){
	p2[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = p2[i - 1] * 2 % mod;
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}