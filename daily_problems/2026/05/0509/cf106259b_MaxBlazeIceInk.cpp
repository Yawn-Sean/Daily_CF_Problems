#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define MAXN 1000005
#define mod 998244353

int inv[MAXN];

inline int C( int n , int m ){
	if( n < m || m < 0 ) return 0;
	int res = 1;
	while( m ){
		res = 1ll * res * n % mod;
		res = 1ll * res * inv[m] % mod;
		n --,m --;
	}
	return res;
}

int n,k,a[MAXN],f[2][MAXN],cnt[MAXN],ans[MAXN],pre[20],p2[20];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void solve(){
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),cnt[a[i]] ++;
	f[0][1] = 1;
	int Lim = min( k - 1 , 19 ),now = 0;
	for( int i = 0 ; i <= Lim ; i ++ ) pre[i] = C( k - 1 , i ),p2[i] = fp( cnt[1] , k - 1 - i );
	for( int i = 0 ; i <= Lim ; i ++ ){
		for( int M = 1 ; M <= n ; M ++ )
			chkadd( ans[M] , 1ll * f[now][M] * pre[i] % mod * p2[i] % mod );
		if( i == Lim ) break;
		for( int i = 1 ; i <= n ; i ++ ) f[now ^ 1][i] = 0;
		for( int v = 2 ; v <= n ; v ++ ){
			for( int t = 1 ; t * v <= n ; t ++ )
				chkadd( f[now ^ 1][t * v] , 1ll * f[now][t] * cnt[v] % mod );		
		}
		now ^= 1;
	}
	for( int i = 1 ; i <= n ; i ++ ) cnt[i] += cnt[i - 1];
	int Ans = 0;
	for( int v = 1 ; v <= n ; v ++ ){
		for( int t = 1 ; 1ll * t * v <= n ; t ++ ){
			int l = t * v,r = min( n , ( v + 1 ) * t - 1 );
			chkadd( Ans , 1ll * v * ans[t] % mod * ( cnt[r] - cnt[l - 1] ) % mod );
		}
	}
	printf("%d\n",Ans);
	for( int i = 1 ; i <= n ; i ++ ) cnt[i] = ans[i] = 0,f[0][i] = f[1][i] = 0;
}

signed main(){
	inv[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod;
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}