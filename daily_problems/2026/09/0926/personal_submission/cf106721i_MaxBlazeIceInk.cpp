#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 200005

const double pi = acos(-1);

int n,k,x[MAXN],y[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 0 ; i < n ; i ++ ) scanf("%lld%lld",&x[i],&y[i]);
	double area = 0;
	for( int i = 0 ; i < n ; i ++ ){
		int nxt = ( i + 1 ) % n;
		area += x[i] * y[nxt] - y[i] * x[nxt];
	}
	area = 0.5 * fabs( area );
	if( area >= k ){ puts("0"); return; }
	double D = 0;
	for( int i = 0 ; i < n ; i ++ ){
		int nxt = ( i + 1 ) % n;
		D += sqrtl( ( x[nxt] - x[i] ) * ( x[nxt] - x[i] ) + ( y[nxt] - y[i] ) * ( y[nxt] - y[i] ) );
	}
	//area + pi * r * r + D * r = k
	double delta = D * D - 4 * pi * ( area - k );
	double R = ( -D + sqrtl( delta ) ) / ( 2 * pi );
	printf("%.15Lf\n",R);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}