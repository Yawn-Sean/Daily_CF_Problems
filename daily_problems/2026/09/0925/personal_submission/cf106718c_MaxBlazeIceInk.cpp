#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1005
#define INF (int)1e18

int n,z,v[MAXN],d[MAXN],x[MAXN],f[2][MAXN][105];

inline void chkmax( int &x , int k ){ x = max( x , k ); }

signed main(){
	scanf("%lld%lld",&n,&z);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld%lld",&v[i],&d[i],&x[i]);
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 0 ; j <= d[i] + 1 ; j ++ ) f[0][i][j] = f[1][i][j] = -INF;
	for( int i = 1 ; i <= n ; i ++ ) f[0][i][0] = 0;
	int now = 0;
	for( int i = 1 ; i <= z ; i ++ ){
		for( int j = 1 ; j <= n ; j ++ )
			for( int k = 0 ; k <= d[j] + 1 ; k ++ ) f[now ^ 1][j][k] = -INF;
		//choice1：休息
		int maxx = -INF;
		for( int j = 1 ; j <= n ; j ++ )
			for( int k = 0 ; k <= d[j] + 1 ; k ++ )
				chkmax( maxx , f[now][j][k] );
		for( int j = 1 ; j <= n ; j ++ )
			chkmax( f[now ^ 1][j][0] , maxx );
		//choice2：继续
		for( int j = 1 ; j <= n ; j ++ )
			for( int k = 0 ; k <= d[j] + 1 ; k ++ )
				chkmax( f[now ^ 1][j][min( k + 1 , d[j] + 1 )] , f[now][j][k] + ( k >= d[j] ? ( v[j] - x[j] ) : v[j] ) );
		//choice3：切换
		int w = -INF;
		for( int j = 1 ; j <= n ; j ++ ){
			chkmax( f[now ^ 1][j][1] , w + v[j] );
			for( int k = 0 ; k <= d[j] + 1 ; k ++ ){
				chkmax( w , f[now][j][k] );
			}
		}
		w = -INF;
		for( int j = n ; j >= 1 ; j -- ){
			chkmax( f[now ^ 1][j][1] , w + v[j] );
			for( int k = 0 ; k <= d[j] + 1 ; k ++ ){
				chkmax( w , f[now][j][k] );
			}
		}
		now ^= 1;
	}
	int ans = -INF;
	for( int j = 1 ; j <= n ; j ++ ){
		for( int k = 0 ; k <= d[j] + 1 ; k ++ ){
			chkmax( ans , f[now][j][k] );
		}
	}
	printf("%lld\n",ans);
	return 0;
}