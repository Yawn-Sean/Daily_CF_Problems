#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define MAXN 200005

int n,k,fac[MAXN],inv[MAXN],ifac[MAXN],ivp[MAXN];

inline int C( int n , int m ){
	n %= mod;
	int res = 1,p = 1;
	for( int i = 1 ; i <= m ; i ++ ){
		res = res * n % mod * inv[p] % mod;
		p ++,n = ( n - 1 + mod ) % mod;
	}
	return res;
}

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

//生成一个长度 len 的有序序列
//k-1 个增量放在 len+1 个位置，可空

//Ferrers：期望次数等于 >=1 次的概率 + >=2 次的概率 + ...

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	scanf("%lld%lld",&n,&k);
	ivp[0] = inv[k];
	for( int i = 1 ; i <= n ; i ++ ) ivp[i] = ivp[i - 1] * ivp[i - 1] % mod;
	int ans = 0;
	for( int i = 0 , coef = 1 ; i <= n ; i ++ ){
		//长度为 L 的序列
		int p = C( k + fp( 2 , n - i ) - 1 , k - 1 ) * ivp[n - i] % mod;
		p = mod + 1 - p;
		// cerr << C( k + fp( 2 , n - i ) - 1 , k - 1 ) << " " << ivp[n - i] % mod << "\n";
		// cerr << p << "\n";
		// coef = coef * p % mod;
		chkadd( ans , p );
	}
	printf("%lld\n",ans);
	return 0;
}