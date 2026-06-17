#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,q,a[MAXN],nxt[MAXN][18],lst[MAXN],st[MAXN];

inline void solve(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	for( int i = n ; i >= 1 ; i -- ){
		if( lst[a[i] + 1] ) nxt[i][0] = lst[a[i] + 1];
		lst[a[i]] = i;
		if( lst[1] ) st[i] = lst[1];
	}
	for( int j = 1 ; j < 18 ; j ++ )
		for( int i = 1 ; i <= n ; i ++ )
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r; scanf("%d%d",&l,&r);
		if( !st[l] || st[l] > r ){ printf("1 "); continue; }
		int now = st[l],ans = 2;
		for( int j = 17 ; j >= 0 ; j -- ){
			if( nxt[now][j] && nxt[now][j] <= r ){
				now = nxt[now][j];
				ans += 1 << j;
			}
		}
		printf("%d ",ans);
	}
	puts("");
	for( int i = 1 ; i <= n ; i ++ ){
		lst[i] = st[i] = 0;
		memset( nxt[i] , 0 , sizeof( nxt[i] ) );
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}