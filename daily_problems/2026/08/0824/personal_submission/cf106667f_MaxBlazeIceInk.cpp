#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int n,h,x[MAXN],y[MAXN],r[MAXN],vis[MAXN];

double dis[MAXN];
vector< pair<int,double> > E[MAXN];

signed main(){
	scanf("%d%d",&n,&h);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d%d%d",&x[i],&y[i],&r[i]);
	E[0].emplace_back( make_pair( n + 1 , 1.0 * h ) );
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			double w = 1ll * ( y[i] - y[j] ) * ( y[i] - y[j] ) + 1ll * ( x[i] - x[j] ) * ( x[i] - x[j] );
			w = sqrtl( w );
			double dis = max( 0.0 , w - r[i] - r[j] );
			E[i].emplace_back( make_pair( j , dis ) );
			E[j].emplace_back( make_pair( i , dis ) );
		}
		E[0].emplace_back( make_pair( i , max( 0.0 , 1.0 * ( y[i] - r[i] ) ) ) );
		E[i].emplace_back( make_pair( 0 , max( 0.0 , 1.0 * ( y[i] - r[i] ) ) ) );
		E[i].emplace_back( make_pair( n + 1 , max( 0.0 , 1.0 * ( h - y[i] ) - r[i] ) ) );
	}
	for( int i = 0 ; i <= n + 1 ; i ++ ) dis[i] = 1e18;
	priority_queue< pair<double,int> , vector< pair<double,int> > , greater< pair<double,int> > > Q;
	Q.push( make_pair( dis[0] = 0 , 0 ) );
	while( !Q.empty() ){
		int u = Q.top().second; Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( pair<int,double> p : E[u] ){
			int v = p.first; double w = p.second;
			if( dis[v] > dis[u] + w ){
				dis[v] = dis[u] + w;
				Q.push( make_pair( dis[v] , v ) );
			}
		}
	}
	printf("%.12lf\n",dis[n + 1]);
	return 0;
}