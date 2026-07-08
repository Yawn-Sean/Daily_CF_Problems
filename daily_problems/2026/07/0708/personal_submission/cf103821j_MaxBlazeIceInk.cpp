#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define MAXN 1005

int n,k,cnt[MAXN];
int fac[MAXN],inv[MAXN],ifac[MAXN],pre[MAXN][MAXN];

inline int C( int n , int m ){ return n >= 0 && m >= 0 && n >= m ? fac[n] * ifac[m] % mod * ifac[n - m] % mod : 0; }

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ){ int x; scanf("%lld",&x); cnt[x] ++; }
	int ans = 0;
	for( int i = 0 , coef = 1 ; i <= k ; i ++ ){
		//k - i 个盒子
		int res = 1;
		for( int c = 1 ; c <= n ; c ++ ){
			if( !cnt[c] ) continue;
			res = res * C( k - i + cnt[c] - 1 , k - i - 1 ) % mod;
		}
		ans = ( ans + res * coef % mod * C( k , i ) % mod ) % mod;
		coef = mod - coef;
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) cnt[i] = 0;
}

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	for( int i = 1 ; i <= 1000 ; i ++ ){
		for( int j = 1 ; j <= i ; j ++ )
			pre[i][j] = ( pre[i][j - 1] + C( i , j ) ) % mod;
	}
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}