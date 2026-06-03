#include<bits/stdc++.h>
using namespace std;

int n,d;

inline void solve(){
	scanf("%d%d",&n,&d);
	if( n & 1 ){
		int D = ( n / 2 ) * ( n / 2 ) * 2;
		if( d > D ) puts("NO");
		else{
			puts("YES");
			for( int i = 1 ; i <= n / 2 ; i ++ ){
				for( int j = 1 ; j <= n / 2 ; j ++ ){
					printf("%d %d %d %d\n",i,j,i + n / 2 + 1,j + n / 2 + 1);
					printf("%d %d %d %d\n",i + n / 2 + 1,j + n / 2 + 1,i,j);
				}
			}
			for( int i = 1 ; i <= n / 2 + 1 ; i ++ ){
				for( int j = n / 2 + 1 ; j <= n ; j ++ ){
					printf("%d %d %d %d\n",i,j,i + n / 2,j - n / 2);
					if( i == 1 && j == n || j == n / 2 + 1 && i == n / 2 + 1 ) continue;
					printf("%d %d %d %d\n",i + n / 2,j - n / 2,i,j);
				}
			}
			printf("%d %d %d %d\n",n,1,1,n);
			// printf("%d %d %d %d\n",1,n,n,1);
		}
	}
	else{
		int D = ( n / 2 ) * ( n / 2 ) * 2;
		if( d > D ) puts("NO");
		else{
			puts("YES");
			for( int i = 1 ; i <= n / 2 ; i ++ ){
				for( int j = 1 ; j <= n / 2 ; j ++ ){
					printf("%d %d %d %d\n",i,j,i + n / 2,j + n / 2);
					printf("%d %d %d %d\n",i + n / 2,j + n / 2,i,j);
				}
			}
			for( int i = 1 ; i <= n / 2 ; i ++ ){
				for( int j = n / 2 + 1 ; j <= n ; j ++ ){
					printf("%d %d %d %d\n",i,j,i + n / 2,j - n / 2);
					if( i == n && j == 1 ) continue;
					printf("%d %d %d %d\n",i + n / 2,j - n / 2,i,j);
				}
			}
			// printf("%d %d %d %d\n",n,1,1,n);
		}
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}