#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,m,via[MAXN],ans;
vector< pair<int,int> > E[MAXN];

//简单差分题

void dfs( int x , int fa , int W ){
	for( auto [v,w] : E[x] ){
		if( v == fa ) continue;
		dfs( v , x , w );
		via[x] ^= via[v];
	}
	if( via[x] ) ans += W;
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		E[u].emplace_back( make_pair( v , w ) );
		E[v].emplace_back( make_pair( u , w ) );
	}
	scanf("%lld",&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int a,b; scanf("%lld%lld",&a,&b);
		via[a] ^= 1,via[b] ^= 1;
	}
	dfs( 1 , 0 , 0 );
	printf("%lld\n",ans);
	return 0;
}