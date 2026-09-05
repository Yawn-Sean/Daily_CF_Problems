#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,a[MAXN],A[MAXN],cnt,to[MAXN],f[MAXN],lst[MAXN];

signed main(){
	//just greedy
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),A[++cnt] = a[i];
	sort( A + 1 , A + cnt + 1 );
	cnt = unique( A + 1 , A + cnt + 1 ) - ( A + 1 );
	for( int i = 1 ; i <= n ; i ++ ) a[i] = lower_bound( A + 1 , A + cnt + 1 , a[i] ) - A;
	for( int i = n ; i >= 1 ; i -- ){
		if( lst[a[i] + 1] ) to[i] = to[lst[a[i] + 1]] + 1;
		else to[i] = 1;
		f[a[i]] = max( f[a[i]] , to[i] );
		lst[a[i]] = i;
	}
	for( int i = 1 ; i <= n ; i ++ ) lst[a[i]] = to[i] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( lst[a[i] + 1] ) to[i] = to[lst[a[i] + 1]] + 1;
		else to[i] = 1;
		f[a[i]] = max( f[a[i]] , to[i] );
		lst[a[i]] = i;
	}
	int now = 1,ans = 0;
	while( now <= cnt ) now += f[now],ans ++;
	printf("%d %d\n",cnt,ans);
	return 0;
}