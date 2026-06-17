#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int n;

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void solve(){
	scanf("%lld",&n);
	int p2 = fp( 2 , n ),p22 = fp( 2 , n + 1 );
	int T = ( p2 * ( ( n + 1 ) % mod ) % mod - p22 + mod ) % mod + 1;
	T %= mod;
	int ans = ( p2 - 1 + mod ) % mod * ( ( n + 1 ) % mod ) % mod;
	ans = ( mod - ans ) % mod;
	ans += 2 * T % mod; ans %= mod;
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}