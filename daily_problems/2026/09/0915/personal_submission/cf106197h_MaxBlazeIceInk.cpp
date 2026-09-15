#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,deg[MAXN],ins[MAXN],vis[MAXN];

vector<int> E[MAXN];

inline void clear(){
	for( int i = 1 ; i <= n ; i ++ ){
		deg[i] = ins[i] = vis[i] = 0;
		E[i].clear();
	}
}

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[v].emplace_back( u );
		deg[u] ++;
	}
	queue<int> Q; Q.push( n );
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		for( int v : E[u] ){
			ins[v] ++;
			if( 2 * ins[v] > deg[v] ){
				Q.push( v );
			}
		}
	}
	if( vis[1] ){ puts("-1"); clear(); }
	else{
		vector< pair<int,int> > ans; 
		for( int i = 1 ; i <= n ; i ++ ){
			for( int v : E[i] ){
				if( vis[i] && !vis[v] )
					ans.emplace_back( make_pair( v , i ) );
			}
		}
		printf("%d\n",(int)ans.size());
		for( pair<int,int> ele : ans )
			printf("%d %d\n",ele.first,ele.second);
		clear();
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}