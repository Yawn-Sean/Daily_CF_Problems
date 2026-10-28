#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define mod 998244353

int n,m,tmp[2][MAXN],s[MAXN];
vector<int> E[MAXN];
char ss[MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

inline int reduce( int x ){ return x < 0 ? x + mod : x; }

inline void solve(){
	scanf("%lld%lld",&n,&m);
	E[0].resize( m + 1 );
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%s",ss + 1);
		E[i].resize( m + 1 );
		for( int j = 1 ; j <= m ; j ++ ) E[i][j] = ss[j] == '#';
	}
	for( int i = 1 ; i <= m ; i ++ ){ if( !E[1][i] ) tmp[0][i] = 1; else break; }
	int now = 0;
	for( int i = 2 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= m ; j ++ ) tmp[now ^ 1][j] = 0;
		for( int j = 1 , lst = 0 ; j <= m ; j ++ ){
			if( E[i][j] ){ lst = j; continue; }
			if( E[i - 1][j] ) s[j] = ( s[j - 1] + tmp[now][j - 1] ) % mod;
			else s[j] = s[j - 1],chkadd( tmp[now ^ 1][j] , tmp[now][j] );
			chkadd( tmp[now ^ 1][j] , ( s[j] - s[lst + 1] + mod ) % mod );
		}
		now ^= 1;
	}
	printf("%lld\n",tmp[now][m]);
	for( int i = 0 ; i <= n ; i ++ ) E[i].clear();
	for( int i = 0 ; i <= m ; i ++ ) s[i] = tmp[0][i] = tmp[1][i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}