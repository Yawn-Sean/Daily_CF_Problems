#include<bits/stdc++.h>
using namespace std;

//一共就 2^2n 种有用的 d 有感觉吗

#define int long long
#define MAXN 257

int n,g[MAXN],m[MAXN],S = 0;

inline int calc( int x , int l , int r ){
	if( l == r ) return l;
	int mid = ( l + r ) >> 1;
	int p = calc( x , l , mid ),q = calc( x , mid + 1 , r );
	S += m[p] + m[q];
	if( g[p] < g[q] ){
		if( g[p] + x > g[q] ) return p;
		else return q;
	}
	else{
		if( g[q] + x > g[p] ) return q;
		else return p;
	}
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= 1 << n ; i ++ ) scanf("%lld",&g[i]);
	for( int i = 1 ; i <= 1 << n ; i ++ ) scanf("%lld",&m[i]);
	int ans = calc( 0 , 1 , 1 << n );
	int ans2 = 0;
	for( int i = 1 ; i <= 1 << n ; i ++ )
		for( int j = 1 ; j <= 1 << n ; j ++ ){
			S = 0;
			int d = abs( g[j] - g[i] ) + 1;
			calc( d , 1 , 1 << n );
			if( S > ans )
				ans = S,ans2 = d;
			else if( S == ans ) ans2 = min( ans2 , d );
		}
	printf("%lld\n%lld\n",ans,ans2);
	return 0;
}