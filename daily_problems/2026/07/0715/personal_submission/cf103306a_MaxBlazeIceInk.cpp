#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 14
#define mod 998244353

int n,m,e[MAXN][MAXN],p2[MAXN * MAXN],g[1 << MAXN];
int f[1 << MAXN][MAXN + 1],In[1 << MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }
inline int reduce( int x ){ return x < 0 ? x + mod : x; }

signed main(){
	p2[0] = 1;
	for( int i = 1 ; i < MAXN * MAXN ; i ++ ) p2[i] = p2[i - 1] * 2 % mod;
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v); u --,v --;
		e[u][v] = e[v][u] = 1;
	}
	for( int S = 0 ; S < 1 << n ; S ++ )
		for( int i = 0 ; i < n ; i ++ )
			for( int j = 0 ; j < n ; j ++ )
				In[S] += e[i][j] & ( S >> i & 1 ) & ( S >> j & 1 ) & ( i < j );
	//考虑先求 g
	g[0] = 1;
	for( int S = 1 ; S < 1 << n ; S ++ ){
		int x = 0; while( !( S >> x & 1 ) ) x ++;
		g[S] = p2[In[S]];
		int SS = S ^ ( 1 << x );
		if( S != ( 1 << x ) ) g[S] = reduce( g[S] - p2[In[SS]] );
		for( int T = ( SS - 1 ) & SS ; T ; T = ( T - 1 ) & SS ){
			//钦定 T 与 x 连通
			g[S] = reduce( g[S] - g[T ^ ( 1 << x )] * p2[In[SS ^ T]] % mod );
		}
	}
	f[0][0] = 1;
	for( int S = 1 ; S < 1 << n ; S ++ ){
		int x = 0;
		while( !( S >> x & 1 ) ) x ++;
		int SS = S ^ ( 1 << x );
		for( int i = 0 ; i < n ; i ++ ) chkadd( f[S][i + 1] , f[SS][i] );
		for( int T = SS ; T ; T = ( T - 1 ) & SS ){
			for( int i = 0 ; i < n ; i ++ )
				chkadd( f[S][i + 1] , f[SS ^ T][i] * g[T ^ ( 1 << x )] % mod );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld\n",f[( 1 << n ) - 1][i]);
	return 0;
}