#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 12

int n,x[MAXN],y[MAXN];
double f[1 << MAXN][MAXN],dis[MAXN][MAXN];

inline void chkmin( double &x , double k ){ x = min( x , k ); }

signed main(){
	scanf("%lld",&n);
	for( int i = 0 ; i < n ; i ++ ) scanf("%lld%lld",&x[i],&y[i]);
	double ans = 1e18;
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = i + 1 ; j < n ; j ++ ){
			int dx = x[j] - x[i],dy = y[j] - y[i];
			double Len = sqrtl( dx * dx + dy * dy );
			//认为一个 d 的贡献是在两个方向上的投影长度之和，考虑点乘
			for( int u = 0 ; u < n ; u ++ ){
				for( int v = u + 1 ; v < n ; v ++ ){
					int Dx = x[v] - x[u],Dy = y[v] - y[u];
					dis[u][v] = dis[v][u] = fabs( 1.0 * ( Dx * dx + Dy * dy ) / Len ) + fabs( 1.0 * ( Dx * -dy + Dy * dx ) / Len );
					// cerr << u << " " << v << " " << dis[u][v] << "\n";
				}
			}
			for( int S = 0 ; S < 1 << n ; S ++ )
				for( int i = 0 ; i < n ; i ++ ) f[S][i] = 1e18;
			for( int i = 0 ; i < n ; i ++ ) f[1 << i][i] = 0;
			for( int S = 0 ; S < 1 << n ; S ++ ){
				for( int i = 0 ; i < n ; i ++ ){
					if( !( S >> i & 1 ) ) continue;
					for( int j = 0 ; j < n ; j ++ ){
						if( S >> j & 1 ) continue;
						chkmin( f[S ^ ( 1 << j )][j] , f[S][i] + dis[i][j] );
					}
				}
			}
			for( int i = 0 ; i < n ; i ++ ) chkmin( ans , f[( 1 << n ) - 1][i] );
			// cerr << i << " " << j << " " << ans << "\n";
		}
	}
	printf("%.12Lf\n",ans);
	return 0;
}