#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005

int n,m,vis[MAXN];
vector<int> E[MAXN];
vector< pair<int,int> > Ans;

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v );
		E[v].emplace_back( u );
	}
	for( int u = 1 ; u <= n ; u ++ ){
		for( int v : E[u] ){
			if( v > u && !vis[v] ) Ans.emplace_back( make_pair( u , v ) );
			vis[v] = 1;
		}
		for( int v : E[u] ){
			for( int w : E[v] ){
				if( w != v && w != u && !vis[w] && w > u ){
					Ans.emplace_back( make_pair( u , w ) );
					vis[w] = 1;
				}
			}
		}
		for( int i = 1 ; i <= n ; i ++ ) vis[i] = 0;
	}
	printf("%d\n",(int)Ans.size());
	for( auto &[u,v] : Ans ) printf("%d %d\n",u,v);
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear();
	Ans.clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}