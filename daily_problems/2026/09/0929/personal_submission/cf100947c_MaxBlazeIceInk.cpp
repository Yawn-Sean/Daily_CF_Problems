#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 20005
#define INF (int)1e18

int n,a[MAXN];

inline void solve(){
	//1 5 3 2 4 1 5 3 2 4
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),a[i + n] = a[i];
	int odd = 0,eve = 0,ans = -INF;
	for( int i = 1 ; i <= 2 * n ; i ++ ){
		if( i & 1 ){
			odd += a[i];
			if( i > n ) odd -= a[i - n - 1];
			if( i >= n ) ans = max( ans , odd ); 
		}
		else{
			eve += a[i];
			if( i > n ) eve -= a[i - n - 1];
			if( i >= n ) ans = max( ans , eve );
		}
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}