#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define mod 998244353
#define iv2 499122177

int n,x[MAXN],s[MAXN],at[MAXN],p2[MAXN],ip2[MAXN];

signed main(){
	p2[0] = ip2[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = p2[i - 1] * 2 % mod,ip2[i] = ip2[i - 1] * iv2 % mod;
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&x[i],&s[i]);
	int t = 0;
	for( int i = 1 , c = 0 ; i <= n ; i ++ ){
		if( s[i] + c == 1 ) at[i] = 1;
		c = ( s[i] + c ) / 2;
	}
	int ans = 0;
	for( int i = n , sum = 0 ; i >= 1 ; i -- ){
		if( at[i] ) sum += p2[i - 1],sum %= mod;
		ans = ( ans + ( x[i] - x[i - 1] ) * sum % mod * ip2[i - 1] % mod );
	}
	printf("%lld\n",( ans + x[n] + 1) % mod );
	return 0;
}