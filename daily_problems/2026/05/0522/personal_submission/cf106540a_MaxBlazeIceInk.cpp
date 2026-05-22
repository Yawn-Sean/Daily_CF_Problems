#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005
#define mod 998244353

int n,k,border[MAXN],f[MAXN];
char s[MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

inline void solve(){
	scanf("%d%d%s",&n,&k,s + 1);
	for( int i = 1 ; i <= n ; i ++ ) border[i] = 0;
	for( int i = 2 , j = 0 ; i <= n ; i ++ ){
		while( j && s[j + 1] != s[i] ) j = border[j];
		if( s[i] == s[j + 1] ) j ++; border[i] = j;
	}
	f[0] = 1;
	for( int i = 1 ; i <= k ; i ++ ) f[i] = 0;
	for( int i = 1 ; i <= k ; i ++ )
		for( int j = 1 ; j <= min( i , n ) ; j ++ )
			if( !border[j] ) chkadd( f[i] , f[i - j] );
	printf("%d\n",f[k]);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}