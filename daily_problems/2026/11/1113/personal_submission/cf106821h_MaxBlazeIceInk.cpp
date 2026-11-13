#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,m,a[MAXN],vis[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&a[i]);
		if( a[i] <= n ) vis[a[i]] ++;
	}
	//猛拉一杆做法
	int mex = 0;
	while( vis[mex] ) mex ++;
	if( !mex ){ puts("Tie"); return 0; }
	for( int i = 0 ; i < mex ; i ++ ){
		if( vis[i] == 1 ){
			puts("Dinny");
			return 0;
		}
	}
	if( n % 2 ) puts("Dinny");
	else puts("Tie");
	return 0;
}