#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,a[MAXN],lst[MAXN],l2[MAXN],l3[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int L = 0,ans = 0,L2 = 0;
	for( int r = 1 ; r <= n ; r ++ ){
		if( a[r] == 1 ) l3[1] = l2[1],l2[1] = lst[1],lst[1] = r;
		if( a[r] == 2 ) l2[2] = lst[2],lst[2] = r;
		if( a[r] >= 3 ) L = r;
		else lst[a[r]] = r;
		if( a[r] >= 2 ) L2 = r;
		if( lst[1] && lst[2] && lst[0] ){
			int rr = min( { lst[0] , lst[1] , lst[2] } );
			int l = max( { L , l2[1] , l2[2] } );
			ans += max( 0ll , rr - l );
		}
		if( l2[1] && lst[0] ){
			int rr = min( lst[0] , l2[1] );
			int l = max( L2 , l3[1] );
			ans += max( 0ll , rr - l );
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	int t = 1;
	while( t -- ) solve();
	return 0;
}