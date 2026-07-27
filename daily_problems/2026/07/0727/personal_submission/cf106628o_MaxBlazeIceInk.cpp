#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

int n,ans[MAXN];

inline void solve(){
	int C = 0;
	scanf("%d",&n);
	ans[1] = 1;
	for( int i = 2 ; i <= n ; i ++ ){
		printf("? %d",i);
		for( int j = 1 ; j <= i ; j ++ ) printf(" %d",j); puts(""),fflush( stdout );
		int P = In();
		ans[i] = i - ( P - C );
		for( int j = i - 1 ; j >= 1 ; j -- ){
			if( ans[j] >= ans[i] ) ans[j] ++;
		}
		C = P;
	}
	printf("!");
	for( int i = 1 ; i <= n ; i ++ ) printf(" %d",ans[i]); puts(""); fflush( stdout );
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}