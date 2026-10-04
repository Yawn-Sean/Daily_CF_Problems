#include<bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define mod 1000000007

int n,k,f[2][MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%d%d",&n,&k);
	f[0][0] = 1;
	// for( int v = 1 ; v <= n ; v ++ )
		// chkadd( ans )
	//离线计数
	int now = 0,ans = 0;
	for( int v = 1 ; v <= n ; v ++ )
		if( n - k * v >= 0 ) chkadd( ans , 1ll * f[now][n - k * v] * v % mod * v % mod );
	for( int i = 1 ; i < k ; i ++ ){
		for( int j = 0 ; j <= n ; j ++ ) f[now ^ 1][j] = 0;
		//加入一个 1
		for( int j = 0 ; j < n ; j ++ )
			chkadd( f[now ^ 1][j + 1] , f[now][j] );
		//集体 +1
		for( int j = 0 ; j <= n ; j ++ )
			if( j + i <= n ) chkadd( f[now ^ 1][j + i] , f[now ^ 1][j] );
		// for( int j = 0 ; j <= n ; j ++ )
			// cerr << j << " " << f[now ^ 1][j] << "\n";
		//v 有大于等于 k - i 个，这里是个 ferrers
		for( int v = 1 ; v <= n ; v ++ ){
			if( n - ( k - i ) * v <= 0 ) continue;
			//f[n - tv][k - t]
			// cerr << i <<
			chkadd( ans , 1ll * f[now ^ 1][n - ( k - i ) * v] * v % mod * v % mod );
		}
		// cerr << ans << "\n";
		now ^= 1;
	}
	printf("%d\n",ans);
	return 0;
}