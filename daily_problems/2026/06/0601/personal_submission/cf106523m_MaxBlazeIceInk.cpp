#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define double long double

int n,d[MAXN];
double p[MAXN];

inline bool check( double x ){
	double t = x;
	for( int i = n ; i >= 1 ; i -- )
		x = p[i] * min( x + 1 , (double)d[i] ) + ( 1.0 - p[i] ) * ( x + 1 );
	if( x < t ) return 0;
	return 1;
}

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&d[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%Lf",&p[i]);
	double l = 0,r = 2e6,ans = 0;
	while( fabs( l - r ) > 1e-9 ){
		double mid = ( l + r ) / 2;
		if( check( mid ) ) ans = l = mid;
		else r = mid;
	}
	printf("%.12Lf\n",ans);
	return 0;
}