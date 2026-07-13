#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,d,a[MAXN],b[MAXN],pos[MAXN],posb[MAXN];

inline int calc( int x , int y ){
	// cerr << "calc" << x << " " << y << "\n";
	x = pos[x],y = pos[y];
	if( !y ) return 0;
	if( !x ) return y - 1;
	if( y > x ) return y - x - 1;
	else return y - x + n - 1;
}

signed main(){
	scanf("%lld%lld",&n,&d);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),pos[a[i]] = i;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]),posb[b[i]] = i;
	int Ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) Ans += calc( b[i - 1] , b[i] );
	printf("%lld\n",Ans);
	for( int i = 1 ; i < d ; i ++ ){
		int op; scanf("%lld",&op);
		if( op == 1 ){
			int x,y; scanf("%lld%lld",&x,&y);
			if( posb[a[x]] > posb[a[y]] ) swap( x , y );
			//一坨东西
			Ans -= calc( b[posb[a[x]] - 1] , a[x] );
			Ans -= calc( a[y] , b[posb[a[y]] + 1] );
			Ans -= calc( a[x] , b[posb[a[x]] + 1] );
			if( posb[a[x]] < posb[a[y]] - 1 ){
				// cerr << "asd\n";
				Ans -= calc( b[posb[a[y]] - 1] , a[y] );
			}
			// cerr << Ans << "\n"; //??????
			swap( pos[a[x]] , pos[a[y]] );
			swap( a[x] , a[y] );
			if( posb[a[x]] > posb[a[y]] ) swap( x , y );
			Ans += calc( b[posb[a[x]] - 1] , a[x] );
			Ans += calc( a[y] , b[posb[a[y]] + 1] );
			Ans += calc( a[x] , b[posb[a[x]] + 1] );
			if( posb[a[x]] < posb[a[y]] - 1 )
				Ans += calc( b[posb[a[y]] - 1] , a[y] );
		}
		else{
			int x,y; scanf("%lld%lld",&x,&y);
			Ans -= calc( b[x - 1] , b[x] );
			Ans -= calc( b[y] , b[y + 1] );
			Ans -= calc( b[x] , b[x + 1] );
			if( x < y - 1 )
				Ans -= calc( b[y - 1] , b[y] );
			swap( posb[b[x]] , posb[b[y]] );
			swap( b[x] , b[y] );
			Ans += calc( b[x - 1] , b[x] );
			Ans += calc( b[y] , b[y + 1] );
			Ans += calc( b[x] , b[x + 1] );
			if( x < y - 1 )
				Ans += calc( b[y - 1] , b[y] );
		}
		printf("%lld\n",Ans);
	}
	return 0;
}