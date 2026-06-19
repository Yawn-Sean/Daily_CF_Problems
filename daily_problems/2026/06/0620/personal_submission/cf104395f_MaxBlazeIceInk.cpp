#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
#define mod 1000000007

int n,m,fac[MAXN],inv[MAXN],ifac[MAXN],to[MAXN],vis[MAXN],f[MAXN];

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

signed main(){
	fac[0] = inv[1] = ifac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	for( int i = 2 ; i < MAXN ; i ++ ) inv[i] = ( mod - mod / i ) * inv[mod % i] % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) ifac[i] = ifac[i - 1] * inv[i] % mod;
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i;
	int ans = 0;
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		if( find( u ) != find( v ) ) f[find( u )] = find( v );
		else ans ++;
	}
	n -= m;
	//形成的概率是
	// cerr << n << " " << m << " " << ans << "\n";
	int res = 0;
	for( int x = 1 ; x <= n ; x ++ )
		res = ( res + C( n , x ) * fac[x - 1] % mod * fac[n - x] % mod ) % mod;
	cerr << res << "\n";
	ans = ( ans + res * ifac[n] % mod ) % mod;
	//1 2 3 8
	//4 9
	//5
	//6&7
	printf("%lld\n",ans);
	return 0;
}