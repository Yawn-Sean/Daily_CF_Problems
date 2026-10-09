#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,l,r,c[MAXN];
int dp[MAXN],tmp[MAXN],vis[MAXN],ans;

const int V = 200000;

inline int calc( int cc ){
	int res = 0;
	for( int i = l ; i <= r ; i ++ ){
		int p = dp[i];
		for( int j = i , t = 0 ; j >= 0 ; j -= cc , t ++ )
			p = min( p , dp[j] + t );
		res += p;
	}
	return res;
}

//实际上是调和级数的应该

signed main(){
	scanf("%d%d%d",&n,&l,&r);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&c[i]),vis[c[i]] = 1;
	int cc = 0;
	for( int j = l ; j <= r ; j ++ ) cc += vis[j];
	if( cc == r - l + 1 ){ puts("0"); return 0; }
	dp[0] = 0;
	for( int i = 1 ; i <= V ; i ++ ) dp[i] = i;
	for( int j = 1 ; j <= n ; j ++ )
		for( int i = 1 ; i <= V ; i ++ )
			if( i >= c[j] ) dp[i] = min( dp[i] , dp[i - c[j]] + 1 );
	ans = 0; int id = 0;
	for( int i = l ; i <= r ; i ++ ) ans += dp[i];
	for( int cc = l ; cc <= r ; cc ++ ){
		if( vis[cc] ) continue;
		int res = calc( cc );
		if( res < ans ){ ans = res,id = cc; }
		// cerr << ans << "\n";
	}
	for( int cc = 1 ; cc <= V ; cc ++ ){
		if( vis[cc] ) continue;
		int res = calc( cc );
		if( res < ans ){ ans = res,id = cc; }
		// cerr << ans << "\n";
	}
	printf("%lld\n",id);
	return 0;
}