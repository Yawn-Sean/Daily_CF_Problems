#include<bits/stdc++.h>
using namespace std;

#define MAXN 26

int n,vis[MAXN];

inline void solve(){
	scanf("%d",&n);
	if( n == 1 ){ puts("A"); return; }
	if( n % 2 == 0 ){
		printf("%c",char('A' + n / 2 - 1));
		for( int i = n ; i >= 1 ; i -- ){
			if( i == n / 2 ) continue;
			printf("%c",char( 'A' + i - 1 ));
		}
		puts("");
		return;
	}
	else{
		printf("%c",char('A' + n / 2)); vis[n / 2] = 1;
		n --;
		printf("%c",char('A' + n / 2 - 1)); vis[n / 2 - 1] = 1;
		for( int i = n ; i >= 0 ; i -- ){
			if( !vis[i] ){
				printf("%c",i + 'A');
			}
		}
		puts("");
		memset( vis , 0 , sizeof( vis ) );
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}