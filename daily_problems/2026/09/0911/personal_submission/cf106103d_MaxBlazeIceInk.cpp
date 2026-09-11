#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#define MAXN 505

//0 表示上一次染的红色，1 表示上一次染的蓝色
int n,fac[MAXN],inv[MAXN],ifac[MAXN],f[MAXN][MAXN][2];

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

int DP( int i , int j , int op ){
	if( !i || !j ) return 1;
	if( f[i][j][op] != -1 ) return f[i][j][op];
	if( op == 0 ){
		int res = 0;
		for( int k = 1 ; k <= i ; k ++ ) chkadd( res , DP( i - k , j , op ^ 1 ) * C( i , k ) % mod );
		return f[i][j][op] = res;
	}
	else{
		int res = 0;
		for( int k = 1 ; k <= j ; k ++ ) chkadd( res , DP( i , j - k , op ^ 1 ) * C( j , k ) % mod );
		return f[i][j][op] = res;
	}
}

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	memset( f , -1 , sizeof( f ) );
	scanf("%lld",&n);
	printf("%lld\n",( DP( n , n , 0 ) + DP( n , n , 1 ) ) % mod);
	return 0;
}