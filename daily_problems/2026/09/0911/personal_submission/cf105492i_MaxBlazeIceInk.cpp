#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF (int)1e18
#define MAXN 10005

int n,k,t[MAXN],dp[MAXN],f[MAXN];

int p[MAXN],d[MAXN],c[MAXN];

signed main(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&t[i],&f[i]);
	for( int i = 1 ; i <= k ; i ++ ) scanf("%lld%lld%lld",&p[i],&d[i],&c[i]);
	dp[0] = 0;
	for( int i = 1 ; i <= n ; i ++ ) dp[i] = INF;
	for( int i = 1 ; i <= n ; i ++ ){
		dp[i] = min( dp[i] , dp[i - 1] + f[i] );
		for( int j = 1 ; j <= k ; j ++ ){
			int l = i,r = min( i + d[j] - 1 , n ),ans = -1;
			while( l <= r ){
				int mid = ( l + r ) >> 1;
				if( t[mid] <= t[i] + p[j] - 1 ) ans = mid,l = mid + 1;
				else r = mid - 1;
			}
			dp[ans] = min( dp[ans] , dp[i - 1] + c[j] );
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}