#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int n,hasV[MAXN];
char s[MAXN][MAXN];

inline void solve(){
	scanf("%d",&n);
	int c = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%s",s[i] + 1);
		for( int j = 1 ; j <= n ; j ++ ){
			hasV[i] |= s[i][j] == 'H';
		}
		c += hasV[i];
	}
	for( int i = 1 ; i <= n ; i ++ ) hasV[i] = 0;
	printf("%d\n",n);
	if( c == n ){
		for( int i= 1 ; i <= n ; i ++ ){
			for( int j = 1 ; j <= n ; j ++ ){
				if( s[i][j] == 'H' ){ printf("%d %d\n",i,j); break; }
			}
		}
		return;
	}
	else{
		for( int j = 1 ; j <= n ; j ++ ){
			for( int i = 1 ; i <= n ; i ++ ){
				if( s[i][j] == 'V' ){ printf("%d %d\n",i,j); break; }
			}
		}
		return;
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}