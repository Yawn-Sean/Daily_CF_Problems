#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

int hx,hy,cx,cy;

inline double Uni( double l1 , double r1 , double l2 , double r2 ){
	return max( (double)0 , min( r1 , r2 ) - max( l1 , l2 ) );
}

signed main(){
	scanf("%lld%lld%lld%lld",&hx,&hy,&cx,&cy); hx -= cx,hy -= cy;
	if( hypotl( hx , hy ) <= 1 ){ puts("1"); return 0; }
	if( !hx && !hy ){ puts("1"); return 0; }
	double argx = atan2( hy , hx );
	if( argx <= 0 ) argx = argx / acos(-1) * 180 + 360;
	else argx = argx / acos(-1) * 180;
	double argd = asin( (double)1.0 / hypotl( hx , hy ) ) / acos(-1) * 180;
	double argL = argx - argd,argR = argx + argd;
	int D,U; scanf("%lld%lld",&D,&U);
	double L = D - U,R = D + U;
	//直接多转两圈判交集
	double ans = Uni( L , R , argL , argR ) + Uni( L , R , argL - 360 , argR - 360 ) + Uni( L , R , argL + 360 , argR + 360 );
	printf("%.12Lf\n",ans / ( R - L ));
	return 0;
}