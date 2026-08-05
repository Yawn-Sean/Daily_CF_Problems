#include<bits/stdc++.h>
using namespace std;

#define MAXN 405
int n,m,ans[MAXN][MAXN];
char s[MAXN][MAXN];

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 2 ; i <= n + m ; i ++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			int k = i - j; if( k < 1 || k > m ) continue;
			ans[j][k] = i * ( i + 1 );
		}
	}
	puts("YES");
	for( int i = 1 ; i <= n ; i ++ , puts("") )
		for( int j = 1 ; j <= m ; j ++ ) printf("%d ",ans[i][j]);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}