#include<bits/stdc++.h>
using namespace std;

#define MAXN 8005
#define INF (int)1e9

int n,J,f[MAXN][2],vpos[MAXN],vneg[MAXN],dis[MAXN],vis[MAXN];

inline void dijkstra(){
	for( int i = -n ; i <= n ; i ++ ) dis[i + n] = INF;
	dis[0 + n] = 0;
	while( 1 ){
		int minn = INF,id = -n - 1;
		for( int j = -n ; j <= n ; j ++ ){
			if( vis[j + n] ) continue;
			if( dis[j + n] < minn ){
				minn = dis[j + n];
				id = j;
			}
		}
		if( id == -n - 1 ) break;
		vis[id + n] = 1;
		for( int i = -J ; i <= J ; i ++ ){
			if( i == 0 ) continue;
			if( id + i >= -n && id + i <= n )
				dis[id + i + n] = min( dis[id + i + n] , dis[id + n] + ( i < 0 ? vneg[-i] : vpos[i] ) );
		}
	}
}

signed main(){
	scanf("%d%d",&n,&J);
	for( int i = 1 ; i <= J ; i ++ ) scanf("%d",&vpos[i]);
	for( int i = 1 ; i <= J ; i ++ ) scanf("%d",&vneg[i]);
	dijkstra();
	f[0][0] = f[0][1] = f[1][0] = f[1][1] = 0;
	for( int i = 2 ; i <= n ; i ++ ){
		f[i][0] = f[i][1] = INF;
		for( int j = 1 ; j <= min( J , i - 1 ) ; j ++ )
			f[i][0] = min( f[i][0] , dis[j + n] + max( f[j][1] , f[i - j][0] ) );
		for( int j = 1 ; j <= min( J , i - 1 ) ; j ++ )
			f[i][1] = min( f[i][1] , dis[-j + n] + max( f[j][0] , f[i - j][1] ) );
	}
	printf("%d\n",f[n][0]);
	return 0;
}