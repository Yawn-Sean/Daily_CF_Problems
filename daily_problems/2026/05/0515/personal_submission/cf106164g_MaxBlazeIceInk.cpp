#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
#define INF (int)1e18

int n,val[MAXN][8],maxx[MAXN][8];
int ans = 0;

vector< pair<int,int> > E[MAXN];

void dfs( int x , int fa ){
	for( int i = 0 ; i < 8 ; i ++ ) maxx[x][i] = val[x][i];
	for( pair<int,int> p : E[x] ){
		int v = p.first,w = p.second; if( v == fa ) continue;
		dfs( v , x );
		for( int i = 0 ; i < 8 ; i ++ )
			ans = max( ans , maxx[x][i] + maxx[v][7 - i] + w );
		for( int i = 0 ; i < 8 ; i ++ )
			maxx[x][i] = max( maxx[x][i] , maxx[v][i] + w );
	}
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		E[u].emplace_back( make_pair( v , w ) );
		E[v].emplace_back( make_pair( u , w ) );
	}
	for( int i = 1 ; i <= n ; i ++ ){
		int x,y,z; scanf("%lld%lld%lld",&x,&y,&z);
		val[i][0] = x + y + z;
		val[i][1] = x + y - z;
		val[i][2] = x - y + z;
		val[i][3] = x - y - z;
		val[i][4] = -x + y + z;
		val[i][5] = -x + y - z;
		val[i][6] = -x - y + z;
		val[i][7] = -x - y - z;
	}
	dfs( 1 , 0 );
	printf("%lld\n",ans);
	return 0;
}