#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 305
#define INF (int)1e18

int n,k,a[MAXN],dp[MAXN][MAXN],s[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	sort( a + 1 , a + n + 1 );
	for( int i = 1 ; i <= n ; i ++ ) s[i] = s[i - 1] + a[i];
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 0 ; j <= n ; j ++ ) dp[i][j] = INF;
	//每个数都变成某个 ai 且连续吃连续
	dp[0][0] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 0 ; j < i ; j ++ ){
			int aim = j + 1 + ( i - j ) / 2;
			int cost = a[aim] * ( aim - j ) - ( s[aim] - s[j] );
			cost += ( s[i] - s[aim] ) - ( i - aim ) * a[aim];
			// cerr << j << " " << i << " " << cost << "\n";
			//1 2 4 4 4
			for( int t = 0 ; t <= i ; t ++ ){
				dp[i][t + 1] = min( dp[i][t + 1] , dp[j][t] + cost );
			}
		}
	}
	int ans = 0;
	for( int i = n ; i >= 1 ; i -- ){
		if( dp[n][i] <= k ) ans = i;
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}