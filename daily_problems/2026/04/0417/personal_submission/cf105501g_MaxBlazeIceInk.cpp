#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,s[MAXN],f[MAXN],trig[MAXN],vis[MAXN],deg[MAXN],b[MAXN],len;
vector<int> A[MAXN],E[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

void dfs( int x ){
	vis[x] = 1;
	b[++len] = x;
	for( int v : E[x] ){
		if( vis[v] ) continue;
		dfs( v );
	}
}

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i;
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d",&s[i]);
		if( i == s[i] ) continue;
		if( find( i ) != find( s[i] ) )
			f[find( i )] = find( s[i] );
	}
	for( int i = 1 ; i <= n ; i ++ ) A[find( i )].emplace_back( i );
	for( int i = 1 ; i <= n ; i ++ ){
		if( find( i ) == i ){
			for( int ele : A[i] ) deg[ele] ++,deg[s[ele]] ++,E[ele].emplace_back( s[ele] ),E[s[ele]].emplace_back( ele );
			queue<int> Q;
			for( int ele : A[i] ) if( deg[ele] == 1 ) Q.push( ele ),trig[ele] = 0,vis[ele] = 1;
			while( !Q.empty() ){
				int u = Q.front(); Q.pop();
				for( int v : E[u] ){
					if( vis[v] ) continue;
					if( !trig[u] ) trig[v] = 1;
					deg[v] --;
					if( deg[v] == 1 ){
						Q.push( v );
						vis[v] = 1;
					}
				}
			}
			len = 0; int cnt = 0;
			for( int ele : A[i] ){
				if( !vis[ele] && trig[ele] ){
					dfs( ele );
					break;
				}
				if( !vis[ele] ) cnt ++;
			}
			if( !len ) ans += ( cnt + 1 ) / 2;
			for( int i = 1 ; i <= len ; i ++ )
				if( !trig[b[i]] ) trig[b[i % len + 1]] |= 1;
			for( int ele : A[i] ) ans += trig[ele];
		}
	}
	printf("%d\n",ans);
	return 0;
}