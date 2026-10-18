#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,k,d[MAXN],r[MAXN],dif[MAXN],tmp[MAXN];

inline bool check( int x ){
	int res = 0;
	for( int i = 1 ; i <= n ; i ++ ) d[i] = tmp[i];
	for( int i = 1 , now = 0 ; i <= n ; i ++ ){
		now += dif[i];
		d[i] += now;
		if( d[i] < x ){
			now += x - d[i];
			res += x - d[i];
			if( r[i] < n ) dif[r[i] + 1] -= x - d[i];
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) dif[i] = 0;
	return res <= k;
}

signed main(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&d[i]),tmp[i] = d[i];
	for( int i = 1 ; i <= n ; i ++ ){
		int x; scanf("%lld",&x);
		int L = max( 1ll , i - x );
		int R = min( n , i + x );
		r[L] = max( r[L] , R );
	}
	for( int i = 1 ; i <= n ; i ++ ) r[i] = max( r[i] , r[i - 1] );
	int l = 1,r = (int)2e9,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) ) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n",ans);
	return 0;
}