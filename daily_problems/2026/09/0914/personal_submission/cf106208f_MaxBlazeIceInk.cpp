#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 205
#define MAXP 200005
#define INF (int)1e18

int n,m,dis[MAXN][MAXN],L[2][MAXP],R[2][MAXP],loc[2][MAXP];

inline void solve(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= n ; j ++ ) dis[i][j] = i == j ? 0 : INF;
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		dis[u][v] = dis[v][u] = min( dis[u][v] , w );
	}
	for( int k = 1 ; k <= n ; k ++ )
		for( int i = 1 ; i <= n ; i ++ )
			for( int j = 1 ; j <= n ; j ++ )
				dis[i][j] = dis[j][i] = min( dis[i][j] , dis[i][k] + dis[k][j] );
	int A,B; scanf("%lld%lld",&A,&B);
	for( int i = 1 ; i <= A ; i ++ )
		scanf("%lld%lld%lld",&L[0][i],&R[0][i],&loc[0][i]);
	for( int i = 1 ; i <= B ; i ++ )
		scanf("%lld%lld%lld",&L[1][i],&R[1][i],&loc[1][i]);
	int i = 1,j = 1,ans = 0;
	while( i < A && j < B ){
		//写一个对的双指针
		if( R[0][i] < L[1][j + 1] && R[1][j] < L[0][i + 1] ){
			int res = 0;
            for( int p = 1 ; p <= n ; p ++ ){
                int ll1 = R[0][i] + dis[loc[0][i]][p];
                int rr1 = L[0][i + 1] - dis[p][loc[0][i + 1]];
                int ll2 = R[1][j] + dis[loc[1][j]][p];
                int rr2 = L[1][j + 1] - dis[p][loc[1][j + 1]];
                int L = max( ll1 , ll2 ), R = min( rr1 , rr2 );
                if( ll1 > rr1 || ll2 > rr2 || L > R ) continue;
                res = max( res , R - L );
            }
            ans += res;
		}
		if( L[0][i + 1] < L[1][j + 1] ) i ++;
		else j ++;
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}