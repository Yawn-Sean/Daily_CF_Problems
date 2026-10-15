#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define mod 998244353

int n,ans = 1,dp[MAXN][2];
char s[MAXN][MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ )
		scanf("%s",s[i] + 1);
	for( int j = 1 ; j <= n ; j ++ ){
		int lst_u = 0,cons = 0;
		for( int i = 1 ; i <= n ; i ++ ){
			if( s[i][j] != '?' ){
				if( cons ){
					int ent = ( s[i][j] == '#' ) + lst_u;
					if( ent == 2 ) ans = 0;
					if( !ent ) ans = 1ll * ans * ( cons + 1 ) % mod;
				}
				cons = 0;
				lst_u = s[i][j] == '#' ? 1 : 0;
			}
			else{
				cons ++;
			}
		}
		if( cons ){
			int ent = lst_u;
			if( !ent ) ans = 1ll * ans * ( cons + 1 ) % mod;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		int lst_u = 0,cons = 0;
		for( int j = 1 ; j <= n ; j ++ ){
			if( s[i][j] != '?' ){
				if( cons ){
					int ent = ( s[i][j] == '#' ) + lst_u;
					if( ent == 2 ) ans = 0;
					if( !ent ) ans = 1ll * ans * ( cons + 1 ) % mod;
				}
				cons = 0;
				lst_u = s[i][j] == '#' ? 1 : 0;
			}
			else{
				cons ++;
			}
		}
		if( cons ){
			int ent = lst_u;
			if( !ent ) ans = 1ll * ans * ( cons + 1 ) % mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}