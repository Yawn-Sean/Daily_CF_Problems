#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
#define mod 998244353

int n,k,p,fac[MAXN],inv[MAXN],ifac[MAXN];

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void solve(){
	scanf("%lld%lld%lld",&n,&k,&p); p = p * fp( 100 , mod - 2 ) % mod;
	int ans = 0;
	for( int i = 0 , coef = 1 ; i <= k ; i ++ , coef = mod - coef ){
		if( i < k ){
			int c = mod + 1 - p;
			c = c * ( n - k + i ) % mod;
			c = c * fp( k - i , mod - 2 ) % mod;
			c = ( c + 1 ) % mod;
			c = fp( c , n ) % mod;
			c = c * fp( ( k - i ) * fp( n , mod - 2 ) % mod , n ) % mod;
			c = c * coef % mod * C( k , i ) % mod;
			ans = ( ans + c ) % mod;
			// cerr << ans << "\n";
		}
		else{
			ans = ( ans + fp( mod + 1 - p , n ) * coef % mod ) % mod;
		}
	}
	ans = ans * C( n , k ) % mod;
	printf("%lld\n",ans);
}

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}