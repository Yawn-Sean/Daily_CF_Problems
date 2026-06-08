#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
#define mod 1000000007

int n,X,Y,a[MAXN],f[MAXN][2][2];

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%lld%lld%lld",&n,&X,&Y); X = X * fp( Y , mod - 2 ) % mod;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int Ans = 0;
	for( int i = 0 ; i < 30 ; i ++ ){
		for( int j = 0 ; j <= i ; j ++ ){
			memset( f , 0 , sizeof( f ) );
			f[0][0][0] = 1;
			for( int I = 1 ; I <= n ; I ++ ){
				for( int k = 0 ; k < 2 ; k ++ ){
					for( int t = 0 ; t < 2 ; t ++ ){
						int k1 = a[I] >> i & 1,k2 = a[I] >> j & 1;
						chkadd( f[I][k ^ k1][t ^ k2] , f[I - 1][k][t] * X % mod );
						chkadd( f[I][k][t] , f[I - 1][k][t] * ( mod + 1 - X ) % mod );
					}
				}
			}
			// cerr << i << " " << j << " " << f[n][1][1] << "\n";
			if( i == j )
			chkadd( Ans , ( 1ll << i ) * ( 1ll << j ) % mod * f[n][1][1] % mod );
			else
			chkadd( Ans , 2 * ( 1ll << i ) % mod * ( 1ll << j ) % mod * f[n][1][1] % mod );
		}
	}
	printf("%lld\n",Ans);
	return 0;
}