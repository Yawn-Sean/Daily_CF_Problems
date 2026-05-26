#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 20

int n,tim[1 << MAXN];
int d[MAXN],q0[MAXN],c[MAXN],lx[MAXN],rx[MAXN],ly[MAXN],ry[MAXN];

double f[1 << MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 0 ; i < n ; i ++ )
		scanf("%lld%lld%lld%lld%lld%lld%lld",&d[i],&q0[i],&c[i],&lx[i],&rx[i],&ly[i],&ry[i]);
	for( int S = 0 ; S < 1 << n ; S ++ )
		for( int i = 0 ; i < n ; i ++ )
			if( S >> i & 1 ) tim[S] += c[i];
	f[( 1 << n ) - 1] = 0;
	for( int S = ( 1 << n ) - 1 ; S >= 0 ; S -- ){
		for( int i = 0 ; i < n ; i ++ ){
			if( !( S >> i & 1 ) ) continue;
			int nxtc = tim[S];
			if( nxtc > d[i] ) continue;
			double p = 0;
			if( nxtc > ry[i] ) p = 0;
			else if( nxtc <= ly[i] ) p = 1;
			else p = 1.0 * ( ry[i] - nxtc ) / ( ry[i] - ly[i] );
			double q = 1.0 * ( rx[i] + lx[i] ) / 2;
			// if( i == 1 ) cerr << q << " " << q0[i] << " " << p << "\n";
			f[S ^ ( 1 << i )] = max( f[S ^ ( 1 << i )] , f[S] + 1.0 * p * ( q + q0[i] ) + 1.0 * ( 1 - p ) * q0[i] );
		}
	}
	printf("%.12Lf\n",f[0]);
	return 0;
}