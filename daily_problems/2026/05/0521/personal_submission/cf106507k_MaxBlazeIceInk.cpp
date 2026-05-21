#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAXN 200005

int n,k,fac[MAXN],inv[MAXN],ifac[MAXN],siz[MAXN],dp[MAXN];

inline int C( int n , int k ){ return n >= k ? 1ll * fac[n] * ifac[k] % mod * ifac[n - k] % mod : 0; }
inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }
inline int reduce( int x ){ return x < 0 ? x + mod : x; }

vector<int> E[MAXN];

void init( int x , int fa ){
	siz[x] = 1;
	for( int v : E[x] ){
		if( v == fa ) continue;
		init( v , x ),siz[x] += siz[v];
	}
	if( x != 1 ) chkadd( dp[1] , C( siz[x] , k ) );
}

void calc( int x , int fa ){
	for( int v : E[x] ){
		if( v == fa ) continue;
		dp[v] = dp[x];
		chkadd( dp[v] , C( n - siz[v] , k ) );
		dp[v] = reduce( dp[v] - C( siz[v] , k ) );
		calc( v , x );
	}
}

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	init( 1 , 0 ),calc( 1 , 0 );
	for( int i = 1 ; i <= n ; i ++ ) printf("%d ",dp[i]);
	return 0;
}