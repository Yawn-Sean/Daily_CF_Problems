#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 400005

int n,k,dp[MAXN][3][2],fp[MAXN];
char s[MAXN];

int DP( int rem , int now , int op ){
	if( !rem ) return now ? 0 : 1;
	if( dp[rem][now][op] != -1 ) return dp[rem][now][op];
	int res1 = DP( rem - 1 , now , op ^ 1 );
	int res4 = DP( rem - 1 , ( now + fp[n + k - rem] ) % 3 , op ^ 1 );
	int res2 = DP( rem - 1 , ( now * 2 ) % 3 , op ^ 1 );
	int res3 = DP( rem - 1 , ( now * 2 + 1 ) % 3 , op ^ 1 );
	if( res1 == op || res2 == op || res3 == op || res4 == op ) return dp[rem][now][op] = op;
	else return dp[rem][now][op] = op ^ 1;
}

signed main(){
	scanf("%lld%lld%s",&n,&k,s + 1); k *= 2;
	fp[0] = 1;
	for( int i = 1 ; i <= n + k ; i ++ ) fp[i] = fp[i - 1] * 2 % 3;
	int c = 0;
	for( int i = 1 ; i <= n ; i ++ ) c = ( c * 2 + ( s[i] - '0' ) ) % 3;
	memset( dp , -1 , sizeof( dp ) );
	int res = DP( k , c , 0 );
	if( !res ) puts("GIOVANA");
	else puts("JULIA");
	return 0;
}