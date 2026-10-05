#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MAXN 100005
#define INF (int)1e18

int n,m,K,dis[MAXN],vis[MAXN],D[MAXN];
vector< pair<int,int> > E[MAXN];

inline void solve(){
	scanf("%lld%lld%lld",&n,&m,&K);
	for( int i = 1 ; i <= n ; i ++ ) dis[i] = INF,vis[i] = 0;
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		E[u].emplace_back( make_pair( v , w ) );
		E[v].emplace_back( make_pair( u , w ) );
	}
	priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > Q;
	Q.push( make_pair( dis[n] = 0 , n ) );
	while( !Q.empty() ){
		int u = Q.top().second; Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( pair<int,int> p : E[u] ){
			int v = p.first,w = p.second;
			if( dis[u] + w < dis[v] ){
				dis[v] = dis[u] + w;
				Q.push( make_pair( dis[v] , v ) );
			}
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) D[i] = dis[i];
	sort( D + 1 , D + n + 1 );
	for( int i = 2 , sum = D[1] ; i <= n ; i ++ ){
		//1/n * ( sum + ( n - i + 1 )E ) + K = E
		//( i - 1 )E = nK + sum
		int X = n * K + sum,Y = i - 1;
		//e = X / Y
		if( X >= Y * D[i - 1] && X <= Y * D[i] ){
			double e = 1.0 * X / Y;
			printf("%.12Lf\n",min( (double)1.0 * dis[1] , e ));
			for( int i = 1 ; i <= n ; i ++ ) E[i].clear();
			return;
		}
		sum += D[i];
	}
	printf("%lld\n",dis[1]);
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}