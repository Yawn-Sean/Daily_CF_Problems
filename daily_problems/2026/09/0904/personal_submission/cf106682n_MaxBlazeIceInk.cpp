#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define mod 998244353

int n,k,a,fac[MAXN],inv[MAXN],ifac[MAXN];

inline int C( int n , int m ){ return n >= m && n >= 0 && m >= 0 ? fac[n] * ifac[m] % mod * ifac[n - m] % mod : 0; }

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

inline int reduce( int x ){ return x < 0 ? x + mod : x; }

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline int calc( int x ){
	if( x < 0 ) return 0;
	if( x == 0 ) return 1;
	//求长度为 x 的交替序列数量
	return a * fp( a - 1 , x - 1 ) % mod;
}

signed main(){
	scanf("%lld%lld%lld",&n,&k,&a);
	if( n == 1 ){
		if( k == 0 ) printf("%lld\n",a);
		else printf("0");
		return 0;
	}
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	int eve = n / 2,odd = n - eve,ans = 0;
	for( int i = 0 ; i <= k ; i ++ ){
		//i 个分给 eve，k - i 个分给 odd
		int res = C( eve - 1 , i ) * C( odd - 1 , k - i ) % mod;
		chkadd( ans , res * calc( eve - i ) % mod * calc( odd - ( k - i ) ) % mod );
	}
	printf("%lld\n",ans);
	return 0;
}