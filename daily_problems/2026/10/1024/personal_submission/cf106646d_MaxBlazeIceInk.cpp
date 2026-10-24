#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define INF 1e12
#define eps 1e-12
#define MAXN 18

int n,H,k[MAXN];

vector< pair<int,int> > A[MAXN];

double D[MAXN][MAXN],f[1 << MAXN][MAXN];

signed main(){
	scanf("%lld%lld",&n,&H);
	for( int i = 0 ; i < n ; i ++ ){
		scanf("%lld",&k[i]);
		A[i].resize( k[i] );
		for( int j = 0 ; j < k[i] ; j ++ ) scanf("%lld%lld",&A[i][j].first,&A[i][j].second);
	}
	double tot = 0;
	for( int i = 0 ; i < n ; i ++ ){
		int rig = -1e9,lef = 1e9;
		for( auto [x0,y0] : A[i] ) rig = max( rig , x0 );
		for( auto [x0,y0] : A[i] ) lef = min( lef , x0 );
		tot += rig - lef;
		for( int j = 0 ; j < n ; j ++ ){
			if( i == j ) continue;
			int rig = -1e9,lef = 1e9;
			double dis = 1e9;
			for( auto [x0,y0] : A[i] ) rig = max( rig , x0 );
			for( auto [x0,y0] : A[j] ) lef = min( lef , x0 );
			for( auto [X0,Y0] : A[i] ){
				for( int t = 0 ; t < k[j] ; t ++ ){
					int x0 = X0,y0 = Y0;
					auto [x1,y1] = A[j][t];
					auto [x2,y2] = A[j][( t + 1 ) % k[j]];
					//对竖直边判据无效
					if( y0 < min( y1 , y2 ) - eps || y0 > max( y1 , y2 ) + eps ) continue;
					//rig 为原点
					x0 -= rig,x1 -= lef,x2 -= lef;
					// if( i == 0 && j == 1  ) cerr << "??" << x0 << "\n";
					if( y1 == y2 ){ if( y0 == y1 ) dis = min( dis , (double)1.0 * min( x1 , x2 ) - x0 ); continue; }
					else{
						//( y - y1 ) / ( x - x1 ) = ( y1 - y2 ) / ( x1 - x2 )
						double nx = 1.0 * ( y0 - y1 ) * ( x1 - x2 ) / ( y1 - y2 ) + x1;
						// cerr << "爆了" << nx << "\n";if( i == 0 && j == 1 )
						// cerr << x0 << " " << y0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << t << " " << nx - x0 << "bsd\n";
						if( nx < min( x1 , x2 ) - eps || nx > max( x1 , x2 ) + eps ) continue;
						
						// cerr << nx - x0 << "asd\n";
						dis = min( dis , nx - x0 );
					}
				}
			}
			//变量复用这一块
			for( auto [X0,Y0] : A[j] ){
				for( int t = 0 ; t < k[i] ; t ++ ){
					int x0 = X0,y0 = Y0;
					auto [x1,y1] = A[i][t];
					auto [x2,y2] = A[i][( t + 1 ) % k[i]];
					if( y0 < min( y1 , y2 ) - eps || y0 > max( y1 , y2 ) + eps ) continue;
					//lef 为原点
					x0 -= lef,x1 -= rig,x2 -= rig;
					if( y1 == y2 ){ if( y0 == y1 ) dis = min( dis , (double)1.0 * x0 - max( x1 , x2 ) ); continue; }
					else{
						//( y - y1 ) / ( x - x1 ) = ( y1 - y2 ) / ( x1 - x2 )
						double nx = 1.0 * ( y0 - y1 ) * ( x1 - x2 ) / ( y1 - y2 ) + x1;
						if( nx < min( x1 , x2 ) - eps || nx > max( x1 , x2 ) + eps ) continue;
						// if( i == 0 && j == 1 )
						// cerr << x0 << " " << y0 << " " << x1 << " " << y1 << " " << t << " " << x0 - nx << "asd\n";
						dis = min( dis , x0 - nx );
					}
				}
			}
			// cerr << "fin" << dis << "\n";
			D[i][j] = dis;
			// cerr << i << " " << j << " " << D[i][j] << "\n";
			// cerr << D[0][1] << "\n";
		}
	}
	for( int S = 0 ; S < 1 << n ; S ++ )
		for( int i = 0 ; i < n ; i ++ ) f[S][i] = -INF;
	for( int i = 0 ; i < n ; i ++ ) f[1 << i][i] = 0;
	for( int S = 0 ; S < 1 << n ; S ++ ){
		for( int i = 0 ; i < n ; i ++ ){
			if( S >> i & 1 ){
				for( int j = 0 ; j < n ; j ++ ){
					if( S >> j & 1 ) continue;
					f[S ^ ( 1 << j )][j] = max( f[S ^ ( 1 << j )][j] , f[S][i] + D[i][j] );
				}
			}
		}
	}
	double ans = 0;
	for( int i = 0 ; i < n ; i ++ ) ans = max( ans , f[( 1 << n ) - 1][i] );
	printf("%.12Lf\n",tot - ans);
	return 0;
}