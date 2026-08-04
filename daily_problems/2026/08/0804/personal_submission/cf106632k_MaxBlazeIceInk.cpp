#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,k,a[MAXN],d[MAXN],cnt[MAXN][30];

inline int calc( int l , int r ){
	int res = 0;
	for( int j = 0 ; j < 30 ; j ++ ){
		int c = cnt[r][j] - cnt[l][j];
		//1 -> 0,2 -> 2,3 -> 2,4 -> 4
		res += ( c / 2 * 2 ) * ( 1ll << j );
	}
	return res;
}

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),d[i] = a[i] ^ a[i - 1];
	for( int i = 2 ; i <= n ; i ++ )
		for( int j = 0 ; j < 30 ; j ++ )
			cnt[i][j] = cnt[i - 1][j] + ( d[i] >> j & 1 );
	int ans = 0;
	for( int r = 1 ; r <= n ; r ++ ){
		int L = 1,R = r,ans1 = -1;
		while( L <= R ){
			int mid = ( L + R ) >> 1;
			if( calc( mid , r ) <= k ) ans1 = mid,R = mid - 1;
			else L = mid + 1;
		}
		if( ans1 == -1 || calc( ans1 , r ) != k ) continue;
		L = 1,R = r; int ans2 = -1;
		while( L <= R ){
			int mid = ( L + R ) >> 1;
			if( calc( mid , r ) >= k ) ans2 = mid,L = mid + 1;
			else R = mid - 1;
		}
		// cerr << i << " " << ans1 << " " << ans2 
		if( ans1 != -1 && ans2 != -1 && ans2 >= ans1 ) ans += ans2 - ans1 + 1;
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}