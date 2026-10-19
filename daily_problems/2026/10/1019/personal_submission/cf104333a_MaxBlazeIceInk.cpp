#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define MAXN 100005

int n,a[MAXN],b[MAXN],fac[MAXN],inv[MAXN],ifac[MAXN];

inline int C( int n , int m ){ return n >= m && m >= 0 && n >= 0 ? fac[n] * ifac[m] % mod * ifac[n - m] % mod : 0; }
inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]);
	int ans = 0;
	for( int t = 0 ; t < 20 ; t ++ ){
		int ca = 0,cb = 0;
		for( int i = 1 ; i <= n ; i ++ ) ca += a[i] >> t & 1,cb += b[i] >> t & 1;
		for( int i = 0 ; i <= min( cb , ca ) ; i ++ ){
			int c11 = i,c10 = min( n - cb , ca - i ),c01 = min( n - ca , cb - i );
			// cerr << t << " " << i << " " << c11 << " " << c10 << " " << c01 << "\n";
			chkadd( ans , ( 1ll << t ) % mod * ( c10 + c01 ) % mod * C( cb , i ) % mod * C( n - cb , ca - i ) % mod * fac[ca] % mod * fac[n - ca] % mod );
		}
	}
	printf("%lld\n",ans);
	return 0;
}