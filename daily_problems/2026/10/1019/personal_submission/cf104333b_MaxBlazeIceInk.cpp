#include<bits/stdc++.h>
using namespace std;

#define MAXN 16
#define mod 1000000007

int n,a[MAXN],b[MAXN],f[1 << MAXN][2];

signed main(){
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i ++ ) scanf("%d",&a[i]);
	for( int i = 0 ; i < n ; i ++ ) scanf("%d",&b[i]);
	int ans = 0;
	for( int t = 0 ; t < 30 ; t ++ ){
		memset( f , 0 , sizeof( f ) );
		f[0][0] = 1;
		for( int S = 0 ; S < 1 << n ; S ++ ){
			int c = __builtin_popcount( S );
			for( int i = 0 ; i < n ; i ++ ){
				if( S >> i & 1 ) continue;
				int p = ( b[c] + a[i] ) >> t & 1;
				for( int j = 0 ; j < 2 ; j ++ )
					f[S ^ ( 1 << i )][j ^ p] = ( f[S ^ ( 1 << i )][j ^ p] + f[S][j] ) % mod;
			}
		}
		ans += 1ll * f[( 1 << n ) - 1][1] * ( 1 << t ) % mod;
		ans %= mod;
	}
	printf("%d\n",ans);
	return 0;
}