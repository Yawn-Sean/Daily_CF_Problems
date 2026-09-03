#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define INF (int)2e9

int n,a[2][MAXN],dp[MAXN][2],maxx[MAXN],minn[MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[0][i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[1][i]);
	dp[n][0] = a[0][n],dp[n][1] = a[1][n];
	maxx[n] = dp[n][0],minn[n] = dp[n][1];
	for( int i = n - 1 ; i >= 0 ; i -- ){
		dp[i][0] = min( minn[i + 1] , max( a[0][i] , maxx[i + 1] ) );
		dp[i][1] = max( maxx[i + 1] , min( a[1][i] , minn[i + 1] ) );
		maxx[i] = max( maxx[i + 1] , dp[i][0] );
		minn[i] = min( minn[i + 1] , dp[i][1] );
	}
	printf("%d\n",max( min( 0 , minn[0] ) , maxx[0] ));
	return 0;
}