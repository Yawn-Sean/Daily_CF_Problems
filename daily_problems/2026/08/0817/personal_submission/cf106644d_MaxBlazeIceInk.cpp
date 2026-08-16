#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005

int n,a[MAXN],border[MAXN],vis[MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	for( int i = 2 , j = 0 ; i <= n ; i ++ ){
		while( j && a[j + 1] != a[i] ) j = border[j];
		if( a[j + 1] == a[i] ) j ++; border[i] = j;
	}
	int Now = n;
	while( Now ) Now = border[Now],vis[n - Now] = 1;
	int ans = -1;
	for( int i = 1 ; i < n ; i ++ ){
		if( !vis[i] ) ans = i;
		printf("%d ",ans);
	}
	return 0;
}