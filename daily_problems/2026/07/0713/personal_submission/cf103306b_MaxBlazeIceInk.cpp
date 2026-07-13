#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define mod 998244353

int n,m,a[MAXN],f[MAXN],fac[MAXN],inv[MAXN],ifac[MAXN],s[MAXN],Ans[MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }
inline int C( int n , int m ){ return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
inline int reduce( int x ){ return x < 0 ? x + mod : x; }

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

int X[49] = {0,1,2,3,4,5,6,7,8,9,
			10,20,30,40,50,60,70,80,90,
			100,200,300,400,500,600,700,800,900,
			1000,2000,3000,4000,5000,6000,7000,8000,9000,
			10000,20000,30000,40000,50000,60000,70000,80000,90000,
			100000,200000,200001};

int T[49] = {0,1,2,3,4,5,6,7,8,9,
			 1,2,3,4,5,6,7,8,9,
			 1,2,3,4,5,6,7,8,9,
			 1,2,3,4,5,6,7,8,9,
			 1,2,3,4,5,6,7,8,9,
			 1,2,-1};

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	for( int i = 0 ; i <= m ; i ++ ) f[i] = 1ll * C( m , i ) * fp( n - 1 , m - i ) % mod * fp( fp( n , m ) , mod - 2 ) % mod;
	s[0] = f[0];
	for( int i = 1 ; i <= m ; i ++ ) s[i] = f[i],chkadd( s[i] , s[i - 1] );
	// for( int i = 0 ; i <= m ; i ++ ) cerr << i << " " << f[i] << "\n";
	//直接裸算
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j < 48 ; j ++ ){
			int L = X[j],R = X[j + 1] - 1;
			L -= a[i],R -= a[i];
			if( R < 0 ) continue;
			L = max( L , 0 ),R = min( R , m );
			if( L <= R )
				chkadd( Ans[T[j]] , reduce( s[R] - ( L ? s[L - 1] : 0 ) ) );
		}
	}
	for( int i = 1 ; i <= 9 ; i ++ ) printf("%d\n",Ans[i]);
	return 0;
}