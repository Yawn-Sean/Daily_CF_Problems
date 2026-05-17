#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define mod 1000000007

int n,m,p[MAXN],a[MAXN],f[1 << 20],g[1 << 20],popc[1 << 20],p2[MAXN],mul[1 << 20];
vector<int> app[1 << 9];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	p2[0] = 1; for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = 1ll * p2[i - 1] * 2 % mod;
	scanf("%d%d",&n,&m);
	for( int S = 0 ; S < 1 << m ; S ++ ) popc[S] = popc[S >> 1] + ( S & 1 );
	for( int i = 0 ; i < m ; i ++ ) scanf("%d",&p[i]);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d",&a[i]);
		int S = 0;
		for( int j = 0 ; j < m ; j ++ ) if( a[i] % p[j] == 0 ) S ^= 1 << j;
		a[i] = S,f[S] ++;
	}
	for( int i = 0 ; i < m ; i ++ )
		for( int S = 0 ; S < 1 << m ; S ++ )
			if( S >> i & 1 ) f[S ^ ( 1 << i )] += f[S];
	for( int S = 0 ; S < 1 << m ; S ++ ) f[S] = ( p2[f[S]] - 1 + mod ) % mod;
	for( int S = ( 1 << m ) - 1 ; S >= 0 ; S -- ){
		if( popc[S] > 9 ) continue;
		for( int T = S ; ; T = ( T - 1 ) & S ){
			int coef = ( popc[S] - popc[T] ) & 1 ? mod - 1 : 1;
			chkadd( g[T] , 1ll * f[S] * coef % mod );
			if( !T ) break;
		}
	}
	int ans = 0;
	for( int S = 0 ; S < 1 << m ; S ++ ){
		mul[S] = 1;
		for( int j = 0 ; j < m ; j ++ ) if( S >> j & 1 ) mul[S] = 1ll * mul[S] * p[j] % mod;
		chkadd( ans , 1ll * mul[S] * g[S] % mod );
	}
	printf("%d\n",ans);
	return 0;
}