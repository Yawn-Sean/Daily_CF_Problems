#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAXN 1005

int n,a[MAXN][MAXN],ned[MAXN],vis[MAXN],cnt[MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i < n ; i ++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			scanf("%d",&a[i][j]);
		}
	}
	set<int> SS;
	for( int i = 1 ; i <= n ; i ++ ){
		memset( vis , 0 , sizeof( vis ) );
		int c = 0,S = 0;
		for( int j = 1 ; j < n ; j ++ ){
			c += !vis[a[j][i]],S += a[j][i],vis[a[j][i]] = 1;
		}
		if( c == n - 1 ){
			cnt[n * ( n + 1 ) / 2 - S] ++;
			SS.insert( n * ( n + 1 ) / 2 - S );
		}
	}
	int res = 1,p = n;
	for( int i = 1 ; i <= n ; i ++ ) if( cnt[i] ) res = 1ll * res * cnt[i] % mod,p --;
	for( int i = p ; i >= 1 ; i -- ) res = 1ll * res * i % mod;
	printf("%d %d\n",(int)SS.size(),res);
	return 0;
}