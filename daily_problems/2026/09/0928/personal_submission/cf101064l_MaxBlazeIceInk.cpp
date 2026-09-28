#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 2005
#define INF (int)1e18

const int W = 500,Lim = 2000,B = 20000000;

int n,S,w[MAXN],c[MAXN],dp[B + 5];

map<int,int> f;

inline void init(){
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 0 ; j <= Lim ; j ++ )
			if( j + w[i] <= Lim )
				dp[j + w[i]] = max( dp[j + w[i]] , dp[j] + c[i] );
}

int calc( int x ){
	if( x <= Lim )	return dp[x];
	if( x <= B && dp[x] ) return dp[x];
	if( x > B && f.count( x ) ) return f[x];
	int res = -INF;
	int L = x / 2 - W,R = ( x + 1 ) / 2 + W;
	for( int i = L ; i <= R ; i ++ )
		res = max( res , calc( i ) + calc( x - i ) );
	if( x <= B ) return dp[x] = res;
	else return f[x] = res;
}

signed main(){
	scanf("%lld%lld",&n,&S);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&w[i],&c[i]);
	init();
	printf("%lld\n",calc( S ));
	return 0;
}