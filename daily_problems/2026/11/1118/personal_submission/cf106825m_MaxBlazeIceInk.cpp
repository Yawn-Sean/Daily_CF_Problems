#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
#define MAXN 155

int n,k,dp[2][MAXN][MAXN][MAXN];
char s[4][MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%d%d%s",&n,&k,s[1] + 1);
	memcpy( s[2] , s[1] , sizeof( s[2] ) );
	sort( s[2] + 1 , s[2] + n + 1 );
	memcpy( s[3] , s[2] , sizeof( s[3] ) );
	reverse( s[3] + 1 , s[3] + n + 1 );
	// cerr << s[1] + 1 << " " << s[2] + 1 << " " << s[3] + 1  << "\n";
	dp[0][0][1][1] = 1;
	int now = 0;
	for( int i = 0 ; i < n ; i ++ ){
		memset( dp[now ^ 1] , 0 , sizeof( dp[now ^ 1] ) );
		for( int c1 = 0 ; c1 <= i ; c1 ++ ){
			for( int c2 = 0 ; c2 <= i + 1 ; c2 ++ ){
				for( int c3 = 0 ; c3 <= i + 1 ; c3 ++ ){
					chkadd( dp[now ^ 1][c1 + ( s[1][i + 1] != '0' )][c2 + ( s[2][i + 1] != '0' )][c3 + ( s[3][i + 1] != '0' )] , dp[now][c1][c2][c3] );
					chkadd( dp[now ^ 1][c1 + ( s[1][i + 1] != '1' )][c2 + ( s[2][i + 1] != '1' )][c3 + ( s[3][i + 1] != '1' )] , dp[now][c1][c2][c3] );
				}
			}
		}
		now ^= 1;
	}
	int ans = 0;
	for( int i = 0 ; i <= n ; i ++ )
		for( int j = 0 ; j <= n + 1 ; j ++ )
			for( int t = 0 ; t <= n + 1 ; t ++ )
				if( min( { i , j , t } ) <= k )
					chkadd( ans , dp[now][i][j][t] );
	printf("%d\n",ans);
	return 0;
}