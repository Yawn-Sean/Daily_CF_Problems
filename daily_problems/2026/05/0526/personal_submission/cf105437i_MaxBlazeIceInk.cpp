#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define MAXN 2000005
#define mod 1000000007
#define MAXV 5005

int n,m,r[MAXN],c1[MAXV],c2[MAXV];
int dp[MAXV][MAXV];

inline void chkmax( int &x , int k ){ x = max( x , k ); }

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&r[i]);
	//dp[i][j] 前 i 个 apply 完有 j 个 1 能过的最多 check 数量
	int c_ap = 0;
	for( int t = 1 ; t <= n ; t ++ ){
		if( r[t] == 0 ){
			int R = t + 1;
			memset( c1 , 0 , sizeof( c1 ) );
			memset( c2 , 0 , sizeof( c2 ) );
			while( R <= n && r[R] ){
				if( r[R] > 0 ) c1[r[R]] ++;
				else c2[-r[R]] ++;
				R ++;
			}
			for( int i = 1 ; i <= m ; i ++ ) c1[i] += c1[i - 1];
			for( int i = 1 ; i <= m ; i ++ ) c2[i] += c2[i - 1];
			for( int i = 0 ; i <= c_ap ; i ++ ){
				int I = i,J = c_ap - i;
				//apply I
				chkmax( dp[c_ap + 1][I + 1] , dp[c_ap][I] + c2[J] + c1[I + 1] );
				//apply J
				chkmax( dp[c_ap + 1][I] , dp[c_ap][I] + c2[J + 1] + c1[I] );
			}
			c_ap ++;
		}
	}
	int ans = 0;
	for( int i = 0 ; i <= c_ap ; i ++ ) chkmax( ans , dp[c_ap][i] );
	printf("%d\n",ans);
}

signed main(){
	// p2[0] = 1;
	// for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = p2[i - 1] * 2 % mod;
	int t = 1;
	while( t -- ) solve();
	return 0;
}