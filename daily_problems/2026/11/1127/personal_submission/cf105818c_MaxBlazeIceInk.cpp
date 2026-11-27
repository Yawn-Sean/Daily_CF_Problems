#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
#define MAXN 2000005

int a,b,c,d,fac[MAXN],inv[MAXN],ifac[MAXN];

inline void solve(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	//放一个 a，然后放置 BA=i BD=j CD=k CA=l 这几种对象，以任意顺序,但是最后一个必须 A 结尾
	a --; if( a + d != b + c ){ puts("0"); return; }
	//i+j=b
	//i+l=a
	//j+k=d
	//k+l=c
	int ans = 0;
	for( int i = 0 ; i < MAXN ; i ++ ){
		int j = b - i,l = a - i,k = c - l;
		if( j >= 0 && l >= 0 && k >= 0 ){
			if( i + l == 0 ) continue;
			// cerr << i << " " << j << " " << k << " " << l << "\n";
			int res = 1ll * fac[( a + b + c + d ) / 2 - 1] * ifac[i - 1] % mod * ifac[j] % mod * ifac[k] % mod * ifac[l] % mod;
			int res2 = 1ll * fac[( a + b + c + d ) / 2 - 1] * ifac[i] % mod * ifac[j] % mod * ifac[k] % mod * ifac[l - 1] % mod;
			ans = ( ans + res ) % mod;
			ans = ( ans + res2 ) % mod;
		}
	}
	printf("%d\n",ans);
}

/*
*....
.*...
..*..
...*.
....*

*/

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}