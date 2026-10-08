#include<bits/stdc++.h>
using namespace std;

#define MAXN 105
int n,k,vis[MAXN],ans[MAXN];

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

inline int Ask(){
	printf("? ");
	for( int i = 1 ; i <= n ; i ++ ){
		printf("%d",vis[i]);
	}
	puts(""); fflush( stdout );
	return In();
}

signed main(){
	scanf("%d%d",&n,&k);
	//找最开始的四个
	vis[1] = vis[2] = vis[3] = 1;
	int pnt = 0;
	for( int i = 4 ; i <= n ; i ++ ){
		vis[i] = 1;
		if( Ask() ){
			pnt = i;
			break;
		}
	}
	for( int i = 1 ; i <= pnt ; i ++ ){
		vis[i] = 0;
		if( !Ask() ){
			ans[i] = 1;
			vis[i] = 1;
		}
	}
	for( int i = pnt + 1 ; i <= n ; i ++ ){
		vis[i] = 1;
		if( Ask() ) ans[i] = 0;
		else ans[i] = 1,vis[i] = 0;
	}
	printf("! ");
	for( int i = 1 ; i <= n ; i ++ ) printf("%d",ans[i]);
	puts(""); fflush( stdout );
	return 0;
}