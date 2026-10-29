#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define INF (int)1e18

int d,l,n,p[MAXN],a[MAXN],T[MAXN],ts[MAXN],tcnt,tr[MAXN],dp[MAXN];

inline void chkmin( int x , int k ){ for( ; x <= tcnt ; x += x & -x ) tr[x] = min( tr[x] , k ); }
inline int minn( int x ){ int ret = INF; for( ; x ; x -= x & -x ) ret = min( ret , tr[x] ); return ret; }

signed main(){
	scanf("%lld%lld%lld",&d,&l,&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld",&p[i],&a[i]);
		T[i] = a[i] - 2 * p[i],ts[++tcnt] = T[i];
	}
	sort( ts + 1 , ts + tcnt + 1 );
	tcnt = unique( ts + 1 , ts + tcnt + 1 ) - ( ts + 1 );
	for( int i = 1 ; i <= n ; i ++ )
		T[i] = lower_bound( ts + 1 , ts + tcnt + 1 , T[i] ) - ts;
	for( int i = 1 ; i <= tcnt ; i ++ ) tr[i] = INF;
	int ans = INF;
	if( d <= l ) ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		dp[i] = INF;
		if( a[i] + 2 * p[i] <= 2 * l ) dp[i] = a[i];
		int tt = 2 * l - ( a[i] + 2 * p[i] );
		int id = upper_bound( ts + 1 , ts + tcnt + 1 , tt ) - ts - 1;
		if( id >= 1 ){
			dp[i] = min( dp[i] , minn( id ) + a[i] );
		}
		chkmin( T[i] , dp[i] );
		if( a[i] + 2 * ( d - p[i] ) <= 2 * l ){
			ans = min( ans , dp[i] );
		}
	}
	if( ans == INF ) ans = -d - 1;
	printf("%lld\n",d + ans);
	return 0;
}