#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n,m;

inline void solve(){
	scanf("%d%d",&n,&m);
	if( n == 1 ){ puts("1"); return; }
	if( m < n ){
		for( int i = n ; i > n - m ; i -- ) printf("%d ",i);
		for( int i = 1 ; i <= n - m ; i ++ ) printf("%d ",i);
		puts("");
	}
	else{
		if( m % 2 == n % 2 ){
			for( int i = n ; i >= 3 ; i -- ) printf("%d ",i);
			if( n == 2 ) printf("1 2\n");
			else printf("2 1\n");
		}
		else{
			for( int i = n ; i >= 3 ; i -- ) printf("%d ",i);
			printf("2 1\n");
		}
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}