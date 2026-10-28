#include<bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define INF (int)1e9

int n,m,w[MAXN],v[MAXN],dp[MAXN][105],tmp[105];

signed main(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d%d",&w[i],&v[i]);
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 0 ; j <= m ; j ++ ) dp[i][j] = -INF;
	dp[n + 1][0] = 0;
	for( int i = n ; i >= 1 ; i -- )
		for( int j = m ; j >= 0 ; j -- ){
			dp[i][j] = dp[i + 1][j];
			if( j + w[i] <= m )
				dp[i][j + w[i]] = max( dp[i][j + w[i]] , dp[i + 1][j] + v[i] );
		}
	int ans = -INF;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 0 ; j <= m ; j ++ )
			ans = max( ans , tmp[j] + v[i] + dp[i + 1][m - j] );
		// cerr << i << " " << ans << "\n";
		for( int j = m ; j >= 0 ; j -- )
			if( j + w[i] <= m ) tmp[j + w[i]] = max( tmp[j + w[i]] , tmp[j] + v[i] ); 
	}
	printf("%d\n",ans);
	return 0;
}