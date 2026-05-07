#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,k,c[MAXN],vis[MAXN],cnt[MAXN];

inline void solve(){
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&c[i]);
	int mex = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( i != k ){
			vis[c[i]] = 1;
			while( vis[mex] ) mex ++;
		}
	}
	if( c[k] < mex ){printf("%d %d\n",k,n);
	for( int i = 0 ; i <= n ; i ++ ) vis[i] = 0;
	return; }
	puts("-1 -1");
	for( int i = 0 ; i <= n ; i ++ ) vis[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}