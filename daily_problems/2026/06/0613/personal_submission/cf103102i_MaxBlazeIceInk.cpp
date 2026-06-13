#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define mod 1000000007

int n,a[MAXN],dp[MAXN];

vector<int> f[MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%d",&n);
	if( n <= 2 ){ printf("%d\n",n); return 0; }
	for( int i = 3 ; i <= n ; i ++ ){
		for( int j = i ; j <= n ; j += i ){
			if( i != j ) f[i].emplace_back( j );
			if( j + 1 <= n ) f[i].emplace_back( j + 1 );
			if( j + 2 <= n ) f[i].emplace_back( j + 2 );
		}
	}
	for( int i = n - 1 ; i >= 3 ; i -- ){
		dp[i + 1] = 1;
		for( int j : f[i] ) if( j != i + 1 ) chkadd( dp[i + 1] , dp[j] );
	}
	// cerr << dp[4] << "\n";
	int ans = 1;
	for( int i = 4 ; i <= n ; i ++ ) chkadd( ans , dp[i] );
	printf("%lld\n",1ll * ans * 2 % mod * n % mod);
	return 0;
}