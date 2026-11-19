#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

//经典的序列流模型，直接对每条边计算有多少个字母流过

int n,tot[28],lens[MAXN],lent[MAXN],dp[25][25],cnt[28],cnt2[28];
char s[MAXN][22],t[MAXN][22];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%s",s[i] + 1);
		lens[i] = strlen( s[i] + 1 );
		for( int j = 1 ; j <= lens[i] ; j ++ )
			tot[s[i][j] - 'a'] ++;
	}
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%s",t[i] + 1);
		lent[i] = strlen( t[i] + 1 );
		for( int j = 1 ; j <= lent[i] ; j ++ )
			tot[t[i][j] - 'a'] --;
	}
	for( int i = 0 ; i < 26 ; i ++ ) if( tot[i] ){ puts("-1"); return 0; }
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= lens[i] ; j ++ ) cnt[s[i][j] - 'a'] ++;
		for( int j = 1 ; j <= lent[i] ; j ++ ) cnt2[t[i][j] - 'a'] ++;
		for( int j = 0 ; j < 26 ; j ++ ) ans += abs( cnt[j] - cnt2[j] );
		// cerr << ans << "\n";
	}
	//流完之后，保留必要的部分做一个 LCS
	for( int i = 1 ; i <= n ; i ++ ){
		memset( dp , 0 , sizeof( dp ) );
		for( int j = 1 ; j <= lens[i] ; j ++ ){
			for( int k = 1 ; k <= lent[i] ; k ++ ){
				dp[j][k] = max( { dp[j][k - 1] , dp[j - 1][k] , dp[j - 1][k - 1] + ( s[i][j] == t[i][k] ) } );
			}
		}
		ans += lens[i] - dp[lens[i]][lent[i]];
	}
	printf("%lld\n",ans);
	return 0;
}