#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define mod 1000000007

int n,h,f[MAXN][2];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%d",&n);
	f[0][0] = f[0][1] = 1;
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = 1 ; i + j <= n ; j <<= 1 ){
			chkadd( f[i + j][1] , f[i][0] );
			chkadd( f[i + j][0] , f[i][1] );
		}
	}
	printf("%d\n",( f[n][0] + f[n][1] ) % mod);
	return 0;
}