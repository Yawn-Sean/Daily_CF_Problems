#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
#define int long long
#define MAXN 1000005

int n,k,fac[MAXN],inv[MAXN],ifac[MAXN];

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	int q; scanf("%lld",&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int n,k; scanf("%lld%lld",&n,&k);
		printf("%lld\n",C( n + 1 , k + 1 ));
	}
	return 0;
}