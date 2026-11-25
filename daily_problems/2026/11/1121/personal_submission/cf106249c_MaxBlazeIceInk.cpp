#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define MAXN 200005
#define LOGN 62

int n,K,q,nxt[MAXN * LOGN][2],nodecnt,siz[MAXN * LOGN],dp[MAXN * LOGN];
vector< array<int,3> > T[MAXN];

void modify( int &t , int v , int k , int del , int val ){
	if( !t ) t = ++nodecnt;
	if( k == -1 ){
		siz[t] += del;
		if( siz[t] ) dp[t] = val;
		else dp[t] = 0;
		return;
	}
	int ch = v >> k & 1;
	modify( nxt[t][ch] , v , k - 1 , del , val );
	siz[t] = siz[nxt[t][0]] + siz[nxt[t][1]];
	if( !siz[t] ) dp[t] = 0;
	else if( !siz[nxt[t][0]] ) dp[t] = dp[nxt[t][1]] * 2 % mod;
	else if( !siz[nxt[t][1]] ) dp[t] = dp[nxt[t][0]] * 2 % mod;
	else{
		dp[t] = ( dp[nxt[t][0]] + dp[nxt[t][1]] ) % mod;
	}
}

inline void solve(){
	scanf("%lld%lld%lld",&n,&K,&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int d,x,y,c; scanf("%lld%lld%lld%lld",&d,&x,&y,&c);
		T[x].emplace_back( array<int,3>{ 1 , d , c } );
		T[y + 1].emplace_back( array<int,3>{ -1 , d , c } );
	}
	int rt = 0,ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( auto [coef,pos,val] : T[i] )
			modify( rt , pos , K - 1 , coef , val );
		ans = ( ans + dp[rt] ) % mod;
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= nodecnt ; i ++ ) nxt[i][0] = nxt[i][1] = siz[i] = dp[i] = 0;
	for( int i = 1 ; i <= n + 1 ; i ++ ) T[i].clear();
	nodecnt = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}