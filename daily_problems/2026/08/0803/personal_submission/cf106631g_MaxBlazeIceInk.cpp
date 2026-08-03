#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,q,summ[MAXN];
vector< array<int,3> > E;

inline void solve(){
	scanf("%lld%lld",&n,&q);
	int K = 0; while( ( 1 << K ) < n ) K ++;
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r,x,v; scanf("%lld%lld%lld%lld",&l,&r,&x,&v);
		E.emplace_back( array<int,3>{ r + 1 , x , v } );
		E.emplace_back( array<int,3>{ l , x , -v } );
	}
	for( int i = K ; i >= 0 ; i -- ){
		for( auto &[r,x,v] : E ){
			if( r >> i & 1 ){
				int upper = ( r >> ( i + 1 ) << ( i + 1 ) ) & x;
				int lower = x & ( ( 1 << i ) - 1 );
				summ[upper | lower] += v * ( 1ll << ( i - __builtin_popcountl( lower ) ) );
			}
		}
		for( int S = 0 ; S < n ; S ++ )
			if( S >> i & 1 ) summ[S ^ ( 1 << i )] += summ[S]; 
	}
	for( int i = 0 ; i < n ; i ++ ) printf("%lld ",summ[i]);
	puts("");
	for( int j = 0 ; j < n ; j ++ ) summ[j] = 0;
	E.clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}