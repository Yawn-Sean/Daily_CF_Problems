#include<bits/stdc++.h>
#include<cassert>
using namespace std;

#define int long long
#define MAXN 100005
#define MAXK 105
#define LOGX 32
#define INF (int)1e18

int n,m,k,x,y,dp[LOGX][MAXK][MAXK],st[MAXK],ed[MAXK],g[2][MAXK],f2[MAXK];
int topo[MAXN],f[MAXN],Deg[MAXN];
vector<int> E[MAXN];

inline void pre(){
	for( int i = 1 ; i <= n ; i ++ )
		for( int v : E[i] ) Deg[v] ++;
	queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) if( !Deg[i] ) Q.push( i );
	int ord = 0;
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		topo[++ord] = u;
		for( int v : E[u] )
			if( !--Deg[v] ) Q.push( v );
	}
}

inline void calc( int u ){
	for( int i = 1 ; i <= n ; i ++ ) f[i] = -INF; f[u] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		int u = topo[i];
		for( int v : E[u] )
			f[v] = max( f[v] , f[u] + 1 );
	}
}

inline void clear(){
	for( int i = 0 ; i < LOGX ; i ++ )
		for( int j = 1 ; j <= k ; j ++ )
			for( int t = 1 ; t <= k ; t ++ ) dp[i][j][t] = 0;
	for( int i = 1 ; i <= n ; i ++ )
		topo[i] = f[i] = Deg[i] = 0,E[i].clear();
	for( int i = 1 ; i <= k ; i ++ ) st[i] = ed[i] = g[0][i] = g[1][i] = f2[i] = 0;
}

inline void solve(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].emplace_back( v );
	}
	for( int i = 1 ; i <= k ; i ++ ) scanf("%lld%lld",&st[i],&ed[i]);
	pre();
	scanf("%lld%lld",&x,&y);
	calc( y );
	for( int i = 1 ; i <= n ; i ++ ) if( f[i] >= x ){ puts("0"); clear(); return; }
	for( int i = 1 ; i <= k ; i ++ ) g[0][i] = f[st[i]] + 1;
	for( int i = 1 ; i <= k ; i ++ ){
		calc( ed[i] );
		for( int j = 1 ; j <= n ; j ++ ) f2[i] = max( f2[i] , f[j] );
		// if( i == 4 ) cerr << ed[i] << " " << f2[i] << "\n";
		for( int j = 1 ; j <= k ; j ++ ) dp[0][i][j] = f[st[j]] + 1;
	}
	for( int i = 1 ; i < LOGX ; i ++ ){
		for( int u = 1 ; u <= k ; u ++ ){
			for( int v = 1 ; v <= k ; v ++ ){
				dp[i][u][v] = -INF;
				for( int w = 1 ; w <= k ; w ++ ){
					dp[i][u][v] = max( dp[i][u][v] , dp[i - 1][u][w] + dp[i - 1][w][v] );
				}
			}
		}
	}
	for( int i = 1 ; i <= k ; i ++ )
		if( g[0][i] + f2[i] >= x ){ puts("1"); clear(); return; }
	int ans = 2,now = 0;
	for( int j = 31 ; j >= 0 ; j -- ){
		bool flg = 0;
		for( int u = 1 ; u <= k ; u ++ ){
			for( int v = 1 ; v <= k ; v ++ ){
				if( g[now][u] + dp[j][u][v] + f2[v] >= x ){
					// cerr << u << " " << v << " " << g[now][u] << " " << dp[j][u][v] << " " << f2[v] << "\n"; 
					flg = 1;
				}		
			}
		}
		if( !flg ){
			ans += ( 1ll << j );
			for( int u = 1 ; u <= k ; u ++ ) g[now ^ 1][u] = -INF;
			for( int u = 1 ; u <= k ; u ++ ){
				for( int v = 1 ; v <= k ; v ++ ){
					g[now ^ 1][u] = max( g[now ^ 1][u] , g[now][v] + dp[j][v][u] );
				}
			}
			now ^= 1;
		}
	}
	printf("%lld\n",ans);
	clear(); return;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}