#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 105
#define INF (int)1e18

int n,a[MAXN],f[MAXN][MAXN << 1][MAXN];

inline void chkmax( int &x , int k ){ x = max( x , k ); }
const int V = 100;

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 0 ; i <= n ; i ++  )
		for( int j = -V ; j <= V ; j ++ )
			for( int k = 0 ; k <= V ; k ++ )
				f[i][j + V][k] = 0;
	f[0][0 + V][0] = 1;
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = -V ; j <= V ; j ++ ){
			for( int k = 0 ; k <= V ; k ++ ){
				int np = j - a[i + 1];
				if( np >= -V && np <= V )
					chkmax( f[i + 1][np + V][max( k , abs( np ) )] , f[i][j + V][k] );
				np = j + a[i + 1];
				if( np >= -V && np <= V )
					chkmax( f[i + 1][np + V][max( k , abs( np ) )] , f[i][j + V][k] );
			}
		}
	}
	int ans = V;
	for( int i = -V ; i <= V ; i ++ )
		for( int j = 0 ; j <= V ; j ++ ){
			if( f[n][i + V][j] ) ans = min( ans , j );
		}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}