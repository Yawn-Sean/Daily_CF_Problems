#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,m,f[2][2005];
char s[MAXN],t[MAXN];

const int V = 1001;

signed main(){
	scanf("%s%s",s + 1,t + 1);
	n = strlen( s + 1 );
	int ans = 0,now = 0;
	// memset( f[now] , -999999 , sizeof( f[now] ) );
	// f[0][0 + V] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		memset( f[now ^ 1] , -999999 , sizeof( f[now ^ 1] ) );
		for( int j = -V ; j <= V ; j ++ ){
			//f[i][j] = f[i - 1][j]
			if( j < V ) f[now ^ 1][j + V] = max( f[now ^ 1][j + V] , f[now][j + V + 1] );
			//f[i][j] = f[i - 1][j - 1] + ...
			if( i + j >= 1 && i + j <= n )
				f[now ^ 1][j + V] = max( f[now ^ 1][j + V] , f[now][j + V] + ( s[i] == t[i + j] ) );
		}
		for( int j = -V ; j <= V ; j ++ ){
			//f[i][j] = f[i][j - 1]
			if( j > -V ) f[now ^ 1][j + V] = max( f[now ^ 1][j + V] , f[now ^ 1][j + V - 1] );
			ans = max( ans , f[now ^ 1][j + V] );
		}
		now ^= 1;
	}
	if( 100 * ( n - ans ) > n ){ puts("Not brothers :("); return 0; }
	puts("Long lost brothers D:");
	return 0;
}