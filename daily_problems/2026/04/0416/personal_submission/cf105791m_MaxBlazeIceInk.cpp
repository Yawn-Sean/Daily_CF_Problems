#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 10

int n,a[MAXN][MAXN],f[1 << MAXN][MAXN][MAXN];

signed main(){
	scanf("%lld",&n);
	//自环太坑了
	if( n == 1 ){ puts("0"); return 0; }
	for( int i = 0 ; i < n ; i ++ )
		for( int j = 0 ; j < n ; j ++ )
			scanf("%lld",&a[i][j]);
	for( int S = 0 ; S < 1 << n ; S ++ )
		for( int i = 0 ; i < n ; i ++ )
			for( int j = 0 ; j < n ; j ++ ) f[S][i][j] = (int)1e18;
	for( int i = 0 ; i < n ; i ++ ) f[1 << i][i][i] = 0;
	for( int S = 0 ; S < 1 << n ; S ++ )
		for( int i = 0 ; i < n ; i ++ ){
			if( !( S >> i & 1 ) ) continue;
			for( int j = 0 ; j < n ; j ++ ){
				if( !( S >> j & 1 ) ) continue;
				for( int k = 0 ; k < n ; k ++ ){
					if( S >> k & 1 ) continue;
					f[S ^ ( 1 << k )][i][k] = min( f[S ^ ( 1 << k )][i][k] , f[S][i][j] + a[j][k] );
				}
			}
		}
	int ans = (int)1e18;
	for( int i = 0 ; i < n ; i ++ )
		for( int j = 0 ; j < n ; j ++ )
			ans = min( ans , f[( 1 << n ) - 1][i][j] + a[j][i] );
	printf("%lld\n",ans);
	return 0;
}