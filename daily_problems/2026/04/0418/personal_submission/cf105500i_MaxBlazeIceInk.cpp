#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define mod 998244353

int n,a[MAXN],cnt[MAXN],fac[MAXN],inv[MAXN],ifac[MAXN];

inline int C( int n , int m ){ return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
	scanf("%lld",&n);
	int maxx = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),cnt[a[i]] ++,maxx = max( maxx , a[i] );
	int minn = 1; while( !cnt[minn] ) minn ++;
	int sew = cnt[minn],ans = fac[cnt[minn]];
	//钦定最小值在第一项
	for( int i = minn + 1 ; i <= maxx ; i ++ ){
		//填缝隙
		if( cnt[i] < sew ){ puts("0"); return 0; }
		int res = C( cnt[i] - 1 , sew - 1 ) * fac[cnt[i]] % mod;
		ans = ans * res % mod;
		sew = cnt[i] - sew;
	}
	if( sew ){ puts("0"); return 0; }
	ans = ans * inv[cnt[minn]] % mod * n % mod;
	printf("%lld\n",ans);
	return 0;
}