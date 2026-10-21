#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define MAXN 2005

int fac[MAXN],inv[MAXN],ifac[MAXN],a[3],f[MAXN],ans[MAXN];

inline int C( int n , int m ){ return n >= 0 && m >= 0 && n >= m ? fac[n] * ifac[m] % mod * ifac[n - m] % mod : 0; }

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	sort( a , a + 3 );
	if( a[1] == 0 ) ans[1] = 1;
	else{
		//枚举 1 的段数与放在两边的方案数
		for( int i = 1 ; i <= a[1] ; i ++ ){
			//全在中间
			int c = C( a[1] - 1 , i - 1 );
			chkadd( f[2 * i + 1] , C( a[2] - 1 , i ) * c % mod );
			if( i >= 1 ) chkadd( f[2 * i] , 2 * C( a[2] - 1 , i - 1 ) % mod * c % mod );
			if( i >= 2 ) chkadd( f[2 * i - 1] , C( a[2] - 1 , i - 2 ) * c % mod );
		}
		if( a[0] == 0 ){
			for( int i = 1 ; i <= a[1] + a[2] ; i ++ ) ans[i] = f[i];
		}
		else{
			// for( int i = 1 ; i <= a[1] + a[2] ; i ++ ) cerr << i << " " << f[i] << "\n";
			//枚举 0 的段数和 0 占据分界的段数
			for( int i = 1 ; i <= a[0] ; i ++ ){
				int c = C( a[0] - 1 , i - 1 );
				for( int j = 1 ; j <= a[1] + a[2] ; j ++ ){
					for( int t = 0 ; t <= min( i , j - 1 ) ; t ++ ){
						//0 不占边缘
						chkadd( ans[j + ( i - t ) * 2 + t] , c * f[j] % mod * C( j - 1 , t ) % mod * C( a[1] + a[2] - 1 - ( j - 1 ) , i - t ) % mod );
						//0 占一个边缘
						if( t < i )
							chkadd( ans[j + ( i - 1 - t ) * 2 + t + 1] , c * f[j] % mod * C( j - 1 , t ) % mod * 2 % mod * C( a[1] + a[2] - 1 - ( j - 1 ) , i - t - 1 ) % mod );
						if( t < i - 1 )
							chkadd( ans[j + ( i - 2 - t ) * 2 + t + 2] , c * f[j] % mod * C( j - 1 , t ) % mod * C( a[1] + a[2] - 1 - ( j - 1 ) , i - t - 2 ) % mod );
					}
				}
			}
		}
	}
	for( int i = 1 ; i <= a[0] + a[1] + a[2] ; i ++ ) printf("%lld\n",ans[i]);
	return 0;
}