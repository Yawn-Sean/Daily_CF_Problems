#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,k,x,a[MAXN];

inline int Calc( int X ){
	//计算 X - k + ( X - 2k ) + ...
	if( X % k == 0 ) return ( X / k ) * ( X / k - 1 ) / 2 * k;
	int t = ( X + k - 1 ) / k;
	return ( t - 1 ) * ( X % k ) + ( t - 2 ) * ( t - 1 ) / 2 * k;
}

inline void solve(){
	scanf("%lld%lld%lld",&n,&k,&x);
	//操作可逆，正难则反
	for( int i = 1 ; i < n ; i ++ ){
		int l = 1,r = min( a[i] + k , ( n - i ) * k ),ans = 0;
		while( l <= r ){
			int mid = ( l + r ) >> 1;
			if( Calc( mid ) + mid <= x ) ans = mid,l = mid + 1;
			else r = mid - 1;
		}
		// cerr << Calc( 1 ) + 1 << " " << x << "\n";
		// cerr << i << " " << ans << "\n";
		x -= ans,a[i] -= ans,a[i + 1] += ans;
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",a[i]),a[i] = 0; puts("");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}