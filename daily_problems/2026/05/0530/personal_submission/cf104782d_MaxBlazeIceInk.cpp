#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,q,a[MAXN],b[MAXN],c[MAXN],s[MAXN];
int st[MAXN],top,nxt[MAXN][18];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]);
	for( int i = 1 ; i <= n ; i ++ ) c[i] = b[i] - a[i + 1];
	for( int i = 1 ; i <= n ; i ++ ) s[i] = s[i - 1] + c[i];
	for( int i = 0 ; i <= n ; i ++ ){
		while( top && s[i] <= s[st[top]] ) nxt[st[top] + 1][0] = i + 1,top --;
		st[++top] = i;
	} while( top ) nxt[st[top] + 1][0] = n + 1,top --;
	nxt[n + 1][0] = n + 1;
	for( int j = 1 ; j < 18 ; j ++ )
		for( int i = 1 ; i <= n + 1 ; i ++ )
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	scanf("%lld",&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r; scanf("%lld%lld",&l,&r);
		int now = l,ans = 0;
		for( int j = 17 ; j >= 0 ; j -- )
			if( nxt[now][j] <= r ) now = nxt[now][j];
		if( now < r ) ans = s[r - 1] - s[now - 1];
		ans += b[r];
		printf("%lld\n",ans);
	}
	return 0;
}