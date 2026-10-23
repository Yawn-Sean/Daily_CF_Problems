#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAXN 205

int f[MAXN << 1][MAXN][MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	f[0][0][0] = 1;
	for( int i = 0 ; i < ( MAXN << 1 ) - 1 ; i ++ ){
		for( int j = 0 ; j < MAXN ; j ++ ){
			for( int k = 0 ; k < MAXN ; k ++ ){
				if( k + 1 < MAXN )
					chkadd( f[i + 1][max( j , k + 1 )][k + 1] , f[i][j][k] );
				if( k )
					chkadd( f[i + 1][j][k - 1] , f[i][j][k] );
			}
		}
	}
	int t; scanf("%d",&t);
	while( t -- ){
		int h,l; scanf("%d%d",&l,&h);
		printf("%d\n",f[2 * l][h][0]);
	}
	return 0;
}