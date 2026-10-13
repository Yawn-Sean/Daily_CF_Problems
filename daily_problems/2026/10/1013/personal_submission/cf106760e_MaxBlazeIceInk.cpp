#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,a[MAXN],tr[MAXN],f[MAXN],g[MAXN];

inline void chkmax( int x , int k ){ for( ; x <= n ; x += x & -x ) tr[x] = max( tr[x] , k ); }
inline int maxx( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret = max( ret , tr[x] ); return ret; }

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int res = maxx( a[i] - 1 );
		f[i] = res + 1;
		if( a[i] < a[i - 1] ) g[i] = res + 2;
		chkmax( a[i] , f[i] );
		if( a[i] < a[i - 1] ) chkmax( a[i - 1] , g[i] );
		ans = max( ans , max( f[i] , g[i] ) );
	}
	printf("%d\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) tr[i] = f[i] = g[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}