#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 10000005

int n,dp[MAXN],ans = 0;
map<int,int> M;

inline bool judge( int x , int c ){
	while( x ){
		if( x % 10 == c ) return 1;
		x /= 10;
	}
	return 0;
}

void dfs( int x ){
	if( M.count( x ) ) return;
	M[x] = 1;
	ans ++;
	for( int i = 2 ; i < 10 ; i ++ ) if( __int128(x) * i <= __int128(n) && judge( x * i , i ) ) dfs( x * i );
}

signed main(){
	memset( dp , -1 , sizeof( dp ) );
	scanf("%lld",&n);
	if( n <= 9 ){ printf("%lld\n",n); return 0; }
	//可行解特别特别少
	for( int i = 1 ; i <= 9 ; i ++ ) dfs( i );
	printf("%lld\n",ans);
	return 0;
}