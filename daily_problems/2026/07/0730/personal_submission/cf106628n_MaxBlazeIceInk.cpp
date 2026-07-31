#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,k[MAXN],p[MAXN],w[MAXN],dep[MAXN],maxx[18][MAXN],minn[18][MAXN],fa[18][MAXN];
int ans[MAXN];

vector<int> E[MAXN];

void dfs( int x , int fa ){
	dep[x] = dep[fa] + 1;
	for( int v : E[x] ) dfs( v , x );
}

void calc( int x ){
	for( int v : E[x] ) calc( v ),ans[x] += ans[v];
}

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&k[i]);
	for( int i = 2 ; i <= n ; i ++ )
		scanf("%d%d",&p[i],&w[i]),maxx[0][i] = minn[0][i] = w[i],fa[0][i] = p[i],
		E[p[i]].emplace_back( i );
	dfs( 1 , 0 );
	for( int j = 1 ; j < 18 ; j ++ )
		for( int i = 1 ; i <= n ; i ++ )
			maxx[j][i] = max( maxx[j - 1][i] , maxx[j - 1][fa[j - 1][i]] ),
			minn[j][i] = min( minn[j - 1][i] , minn[j - 1][fa[j - 1][i]] ),
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
	for( int i = 1 ; i <= n ; i ++ ){
		int M = 0,m = (int)1e9,now = i;
		for( int j = 17 ; j >= 0 ; j -- ){
			if( fa[j][now] ){
				int nM = max( M , maxx[j][now] );
				int nm = min( m , minn[j][now] );
				if( nM - nm <= k[i] ) now = fa[j][now],M = nM,m = nm;
			}
		}
		// cerr << now << " " << i << "\n";
		ans[i] ++; if( fa[0][now] ) ans[fa[0][now]] --;
	}
	calc( 1 );
	for( int i = 1 ; i <= n ; i ++ ) printf("%d ",ans[i]); puts("");
	for( int j = 0 ; j < 18 ; j ++ ){
		for( int i = 1 ; i <= n ; i ++ ) maxx[j][i] = minn[j][i] = fa[j][i] = dep[i] = ans[i] = k[i] = 0,E[i].clear();
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}