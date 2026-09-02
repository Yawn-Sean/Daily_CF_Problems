#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define iv2 500000004
#define MAXN 1000005

int n,q,a[MAXN],i23[MAXN],i21[MAXN],c[MAXN],p2[MAXN];

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&a[i]);
		for( int j = 0 ; j < 30 ; j ++ )
			c[j] += a[i] >> j & 1;
	}
	for( int i = 0 ; i <= n ; i ++ ) i23[i] = fp( 1 + iv2 , i ),p2[i] = fp( 2 , i );
	for( int i = 0 ; i <= n ; i ++ ) i21[i] = ( fp( 1 + iv2 , i ) - fp( iv2 , i ) + mod ) % mod * iv2 % mod;
	scanf("%lld",&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int p,x; scanf("%lld%lld",&p,&x);
		for( int j = 0 ; j < 30 ; j ++ )
			c[j] -= a[p] >> j & 1;
		a[p] = x;
		for( int j = 0 ; j < 30 ; j ++ )
			c[j] += a[p] >> j & 1;
		int ans = 0;
		for( int j = 0 ; j < 30 ; j ++ ){
			// cerr << c[j] << " " << i23[c[j]] << "\n";
			ans = ( ans + i23[n - c[j]] * i21[c[j]] % mod * p2[n] % mod * p2[j] % mod ) % mod;
			// cerr << ans << "\n";
		}
		printf("%lld\n",ans);
	}
	return 0;
}