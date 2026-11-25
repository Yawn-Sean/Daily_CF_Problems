#include<bits/stdc++.h>
using namespace std;

#define double long double

int a,b;

inline void solve(){
	scanf("%d%d",&a,&b);
	if( a == b ) puts("-1");
	else if( 360 % abs( a - b ) ) puts("-1");
	else{
		if( a < b ) swap( a , b );
		int edg = 360 / abs( a - b );
		double arg = (double)1.0 * ( 180 - a ) / 180 * acos(-1);
		double inarg = 2 * acos( -1 ) / edg;
		//2x^2 - 2x^2cos inarg = len ^ 2 = 2 - 2 * cos arg
		//x^2( 1 - cos inarg ) = 1 - cos arg
		double T = (double)( 1 - cos( arg ) ) / ( 1 - cos( inarg ) );
		double ans = T * sin( inarg ) / 2 * edg + sin( arg ) / 2 * edg;
		// cerr << T * sin( inarg ) / 2 << "\n";
		printf("%.12Lf\n",ans);
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}