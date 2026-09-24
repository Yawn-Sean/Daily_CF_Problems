#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define MAXN 5005

int fac[MAXN],inv[MAXN],ifac[MAXN];
int n,k,p[MAXN],s[MAXN];

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	scanf("%lld%lld",&n,&k);
	int ans = C( n , k );
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&p[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&s[i]);
	for( int i = 1 ; i <= n ; i ++ ){
		int c = 0;
		for( int j = 1 ; j <= n ; j ++ ){
			if( i == j ) continue;
			c += s[i] > s[j] && p[i] > p[j]; 
		}
		if( c >= k - 1 )
			ans = ( ans - C( c , k - 1 ) + mod ) % mod;
	}
	printf("%lld\n",ans);
	return 0;
}