#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

double x,y,z,tx,ty,tz,rr;

signed main(){
	scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf",&x,&y,&z,&tx,&ty,&tz,&rr);
	if( 2 * tx <= x ) tx = x - tx;
	if( 2 * ty <= y ) ty = y - ty;
	if( 2 * tz <= z ) tz = z - tz;
	double l = 0,r = 1.0 * min( { x , y , z } ) / 2,ans = 0;
	for( int i = 1 ; i <= 100 ; i ++ ){
		double mid = ( l + r ) / 2;
		double D = sqrtl( ( tx - mid ) * ( tx - mid ) + ( ty - mid ) * ( ty - mid ) + ( tz - mid ) * ( tz - mid ) );
		if( D >= mid + rr ) ans = mid,l = mid;
		else r = mid;
	}
	printf("%.12Lf\n",ans);
	return 0;
}