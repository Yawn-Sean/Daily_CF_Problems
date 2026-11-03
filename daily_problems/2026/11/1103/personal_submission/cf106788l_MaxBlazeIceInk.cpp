#include<bits/stdc++.h>
using namespace std;

#define MAXN 16

int n,w[MAXN],f[1 << MAXN][1005];

inline void chkmin( int &x , int k ){ x = min( x , k ); }

signed main(){
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i ++ ) scanf("%d",&w[i]);
	for( int S = 0 ; S < 1 << n ; S ++ )
		for( int j = 0 ; j <= 1000 ; j ++ ) f[S][j] = (int)1e9;
	f[0][0] = 0;
	for( int S = 0 ; S < 1 << n ; S ++ ){
		for( int i = 0 ; i < n ; i ++ ){
			if( S >> i & 1 ) continue;
			for( int j = 0 ; j <= 1000 ; j ++ ){
				// if( f[S][j] == (int)1e9 ) continue;
				if( j >= w[i] )
					chkmin( f[S ^ ( 1 << i )][j - w[i]] , max( f[S][j] , j - w[i] ) );
				if( w[i] - j >= 0 && w[i] - j <= 1000 )
					chkmin( f[S ^ ( 1 << i )][w[i] - j] , max( f[S][j] , w[i] - j ) );
				if( w[i] + j <= 1000 )
					chkmin( f[S ^ ( 1 << i )][w[i] + j] , max( f[S][j] , w[i] + j ) );
			}
		}
	}
	int ans = (int)1e9;
	for( int i = 0 ; i <= 1000 ; i ++ )
		ans = min( ans , f[( 1 << n ) - 1][i] );
	printf("%d\n",ans);
	return 0;
}