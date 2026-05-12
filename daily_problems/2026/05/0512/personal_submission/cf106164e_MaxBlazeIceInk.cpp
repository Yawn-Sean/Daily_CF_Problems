#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 105
#define INF (int)1e18

int n,m,q,U[MAXN * MAXN],V[MAXN * MAXN],W[MAXN * MAXN],tim[MAXN * MAXN];
int ps[MAXN * MAXN],pcnt;
int dis[MAXN][MAXN];
int f[MAXN][MAXN * MAXN];

vector<int> E[MAXN * MAXN];

signed main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,p,h; scanf("%lld%lld%lld%lld",&u,&v,&p,&h);
		U[i] = u,V[i] = v,tim[i] = p,W[i] = h;
		ps[++pcnt] = p;
	}
	sort( ps + 1 , ps + pcnt + 1 );
	pcnt = unique( ps + 1 , ps + pcnt + 1 ) - ( ps + 1 );
	for( int i = 1 ; i <= m ; i ++ ){
		tim[i] = lower_bound( ps + 1 , ps + pcnt + 1 , tim[i] ) - ps;
		E[tim[i]].emplace_back( i );
	}
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= n ; j ++ ) dis[i][j] = i == j ? 0 : INF;
	for( int i = 1 ; i <= pcnt ; i ++ ){
		for( int e : E[i] ){
			int u = U[e],v = V[e],w = W[e];
			for( int U = 1 ; U <= n ; U ++ ){
				for( int V = 1 ; V <= n ; V ++ ){
					int upd = dis[U][u] + dis[v][V] + w;
					dis[U][V] = min( dis[U][V] , upd );
				}
			}
		}
		for( int u = 1 ; u <= n ; u ++ ){
			int res = 0;
			for( int v = 1 ; v <= n ; v ++ ) res = max( res , dis[u][v] );
			f[u][i] = res;
		}
	}
	// for( int i = 1 ; i <= pcnt ; i ++ ) cerr << i << " " << f[1][i] << "\n";
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%lld",&op);
		if( op == 1 ){
			int u,h; scanf("%lld%lld",&u,&h);
			int l = 1,r = pcnt,ans = -1;
			while( l <= r ){
				int mid = ( l + r ) >> 1;
				if( f[u][mid] <= h ) ans = mid,r = mid - 1;
				else l = mid + 1;
			}
			if( ans == -1 ) puts("-1");
			else
				printf("%lld\n",ps[ans]);
		}
		else{
			int h; scanf("%lld",&h);
			int ansp = pcnt + 1,ansid = 0;
			for( int u = 1 ; u <= n ; u ++ ){
				int l = 1,r = pcnt,ans = -1;
				while( l <= r ){
					int mid = ( l + r ) >> 1;
					if( f[u][mid] <= h ) ans = mid,r = mid - 1;
					else l = mid + 1;
				}
				if( ans == -1 ) continue;
				else if( ans < ansp ) ansp = ans,ansid = u;
				else if( ans == ansp ) ansid = min( ansid , u );
			}
			if( ansp == pcnt + 1 ) puts("-1 -1");
			else printf("%lld %lld\n",ansid,ps[ansp]);
		}
	}
	return 0;
}