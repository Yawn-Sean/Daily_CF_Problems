#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

inline double Ask( int u , int v ){
	printf("? %lld %lld\n",u,v); fflush( stdout );
	double d; scanf("%Lf",&d);
	return d;
}

inline void solve(){
	double d1 = Ask( 0 , 1 ),d2 = Ask( 1 , 1 );
	double e1 = sqrtl( d1 * d1 + d2 * d2 - sqrtl( 2 ) * d1 * d2 );
	// cerr << e1 << "\n";
	//直接用 d 到 AB 的高作为半边长
	double S = 2 * d1 * d1 * d2 * d2 / e1 / e1;
	// // cerr << alpha * 4 << "\n";
	// double theta = acos(-1) - 2 * alpha;
	// double x = e1 * sin( theta ),y = e1 * cos( theta );
	// double S1 = x * y / 2;
	// // cerr << S1 << "\n";
	// double S2 = d1 * d2 * sqrtl( 2 ) / 2;
	// cerr << (int)( S2 + S1 + 0.5 ) << "\n";
	printf("! %lld\n",(int)( S + 0.5 ));
	fflush( stdout );
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}