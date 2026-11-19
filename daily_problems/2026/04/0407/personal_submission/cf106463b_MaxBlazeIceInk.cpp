#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
#define mod 1000000007

int n,dp[MAXN],siz[MAXN],fac[MAXN],inv[MAXN],ifac[MAXN];
vector<int> E[MAXN];

//理论上每棵子树都有 2 种取法
//全偶数平凡
//存在奇数，确实每个偶数可以任意取，但是奇数必然交替，这里是一个组合数

inline int C( int n , int m ){ return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

void dfs( int x , int fa ){
	siz[x] = 1,dp[x] = 1;
	int od = 0,ev = 0,c = 0;
	for( int v : E[x] ){
		if( v == fa ) continue;
		dfs( v , x ),siz[x] += siz[v];
		od += siz[v] % 2,ev += siz[v] % 2 == 0,c ++;
		dp[x] = dp[x] * dp[v] % mod;
	}
	if( od ){
		for( int i = 1 ; i <= ev ; i ++ ) dp[x] = dp[x] * 2 % mod;
		dp[x] = dp[x] * C( od , od / 2 ) % mod;
	}
}

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	dfs( 1 , 0 );
	printf("%lld\n",dp[1]);
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear(),dp[i] = siz[i] = 0;
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