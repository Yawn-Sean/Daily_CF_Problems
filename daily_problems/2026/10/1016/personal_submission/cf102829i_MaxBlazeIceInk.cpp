#include<bits/stdc++.h>
using namespace std;

#define MAXN 2000005
#define mod 1000000007
#define int long long

int fac[MAXN],inv[MAXN],ifac[MAXN];

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

inline void solve(){
	int x,y; scanf("%lld%lld",&x,&y);
	if( x < 0 ) x = -x;
	if( y < 0 ) y = -y;
	int res = C( x + y + 2 , x + 1 );
	printf("%lld\n",( res - 1 + mod ) % mod);
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