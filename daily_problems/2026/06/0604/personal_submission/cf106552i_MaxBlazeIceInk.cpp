#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
int n,m,q,a[MAXN],dis[50][50];

signed main(){
	scanf("%d%d%d",&n,&m,&q);
	for( int i = 1 ; i <= n ; i ++ ){
		int mi; scanf("%d",&mi);
		for( int j = 1 ; j <= mi ; j ++ ){
			int x; scanf("%d",&x);
			a[i] ^= 1 << ( x - 1 );
		}
	}
	for( int i = 0 ; i < m ; i ++ )
		for( int j = 0 ; j < m ; j ++ ) dis[i][j] = ( i == j ) ? 0 : (int)1e9;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 0 ; j < m ; j ++ ){
			for( int k = 0 ; k < m ; k ++ ){
				if( a[i] >> j & 1 && a[i] >> k & 1 ) dis[j][k] = min( dis[j][k] , 1 );
			}
		}
	}
	for( int k = 0 ; k < m ; k ++ ){
		for( int i = 0 ; i < m ; i ++ ){
			for( int j = 0 ; j < m ; j ++ ){
				dis[i][j] = dis[j][i] = min( dis[i][j] , dis[i][k] + dis[k][j] );
			}
		}
	}
	for( int i = 1 ; i <= q ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		int ans = (int)1e9;
		for( int j = 0 ; j < m ; j ++ ){
			for( int k = 0 ; k < m ; k ++ ){
				if( a[u] >> j & 1 && a[v] >> k & 1 ){
					ans = min( ans , dis[j][k] );
				}
			}
		}
		if( ans > m ) ans = -1; 
		printf("%d\n",ans);
	}
	return 0;
}