#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define eps 1e-12

int n,px,py;
vector< array<double,3> > V;
double ans;

void check( double x , double y ){
	// cerr << "?" << x << " " << y << "\n";
	for( auto &[x0,y0,r0] : V ){
		if( ( x - x0 ) * ( x - x0 ) + ( y - y0 ) * ( y - y0 ) > r0 * r0 + eps ) return;
	}
	ans = min( ans , ( x - px ) * ( x - px ) + ( y - py ) * ( y - py ) );
}

signed main(){
	scanf("%lld%lld%lld",&n,&px,&py);
	V.resize( n );
	for( auto &[x,y,r] : V ) scanf("%Lf%Lf%Lf",&x,&y,&r);
	ans = 1e18;
	check( px , py );
	for( auto &[x,y,r] : V ){
		double R = sqrtl( ( x - px ) * ( x - px ) + ( y - py ) * ( y - py ) );
		if( R <= r ) continue;
		double dx = ( px - x ) / R * r,dy = ( py - y ) / R * r;
		check( x + dx , y + dy );
		//简单相似处理
	}
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = i + 1 ; j < n ; j ++ ){
			auto [X0,Y0,R0] = V[i];
			auto [X1,Y1,R1] = V[j];
			double dx = X1 - X0,dy = Y1 - Y0,d = sqrtl( dx * dx + dy * dy );
			if( d < eps ) continue;
			if( d > R0 + R1 - eps ) continue;
			if( d * d < ( R0 - R1 ) * ( R0 - R1 ) + eps ) continue;
			//余弦定理
			double a = ( R0 * R0 - R1 * R1 + d * d ) / ( 2 * d );
			double h2 = R0 * R0 - a * a;
			double h = sqrtl( h2 );
			double ux = dx / d,uy = dy / d;
			double px = X0 + a * ux,py = Y0 + a * uy;
			double ox = -uy * h,oy = ux * h;

			check( px + ox , py + oy );
			check( px - ox , py - oy );
		}
	}
	printf("%.15Lf\n",sqrtl( ans ));
	return 0;
}