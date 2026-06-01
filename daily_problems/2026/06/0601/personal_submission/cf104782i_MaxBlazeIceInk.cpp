#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000005
#define mod 1000000007

int K,S,T,fac[MAXN],inv[MAXN],ifac[MAXN];

inline int C( int n , int m ){ return n >= m && n >= 0 && m >= 0 ? 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod : 0; }

inline int star_bar( int x , int y ){ return C( x - 1 , y - 1 ); }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	scanf("%d%d%d",&K,&S,&T);
	if( K % T == 0 ){
		int c = K / T;
		if( S % c ){ puts("0"); return 0; }
		int t1 = K / c,t2 = S / c;
		printf("%d\n",C( t2 - 1 , t1 - 1 ));
		return 0;
	}
	int c = K % T,p = K / T,ans = 0;
	for( int s1 = 0 ; s1 <= S ; s1 ++ ){
		if( s1 % ( p + 1 ) ) continue;
		int rem = S - s1;
		if( rem % p ) continue;
		// cerr << s1 << " " << rem << "\n";
		int res = 1ll * star_bar( s1 / ( p + 1 ) , c ) * star_bar( rem / p , T - c ) % mod;
		ans = ( ans + res ) % mod;
		// cerr << ans << "\n";
	}
	printf("%d\n",ans);
	return 0;
}
