#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 500005

int n,m,f[2][MAXN],vis[MAXN];
set<int> E[MAXN];

int find( int id , int x ){ return f[id][x] == x ? x : f[id][x] = find( id , f[id][x] ); }

signed main(){
	scanf("%lld%lld",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) f[0][i] = f[1][i] = i;
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].insert( v ),E[v].insert( u );
		if( find( 0 , u ) != find( 0 , v ) )
			f[0][find( 0 , u )] = find( 0 , v );
	}
	int ans = 0;
	set<int> S;
	for( int i = 1 ; i <= n ; i ++ ) S.insert( i );
	queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) if( !vis[i] ){
		Q.push( i );
		vis[i] = 1;
		S.erase( i );
		while( !Q.empty() ){
			int u = Q.front(); Q.pop();
			for( set<int>::iterator it = S.begin(); it != S.end() ; ){
				int v = *it;
				it ++;
				if( E[u].find( v ) != E[u].end() ) continue;
				f[1][find( 1 , u )] = find( 1 , v );
				S.erase( v );
				vis[v] = 1;
				Q.push( v );
			}
		}
	}
	map< pair<int,int> , int > M;
	for( int i = 1 ; i <= n ; i ++ ){
		ans += M[make_pair( find( 0 , i ) , find( 1 , i ) )],
		M[make_pair( find( 0 , i ) , find( 1 , i ) )] ++;
		// cerr << find( 0 , i ) << " " << find( 1 , i ) << "\n";
	}
	printf("%lld\n",ans);
	return 0;
}