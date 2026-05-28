#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,a[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int r = n,ans = 0,bas = 0;
	for( int i = 1 ; i <= r ; i ++ ){
		a[i] -= bas;
		int t = min( a[i] , r - i + 1 );
		if( a[i] > t ) ans += a[i] - t;
		else
			while( r - i + 1 > t ){
				ans += a[r] - bas;
				r --;
			}
		bas ++; while( r > i && a[r] <= bas ) r --;
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}