#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define INF (int)1e18

int k,l,n,w[MAXN],Fa[MAXN],dp[MAXN],nodecnt,val[MAXN];
vector<int> E[MAXN];

void init( int x , int dep ){
	if( dep < l - 1 ){
		for( int i = 1 ; i <= k ; i ++ ){
			nodecnt ++;
			E[x].emplace_back( nodecnt );
			Fa[nodecnt] = x;
			init( nodecnt , dep + 1 );
		}
	}
}

int getmin( int x ){
	if( !E[x].size() ) return x;
	int minn = (int)INF,id = 0;
	for( int v : E[x] )
		if( dp[v] + val[v] < minn ) minn = dp[v] + val[v],id = v;
	return getmin( id );
}

signed main(){
	scanf("%lld%lld%lld",&k,&l,&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&w[i]);
	if( l == 2 ){
		priority_queue< int , vector<int> , greater<int> > Q;
		for( int i = 1 ; i <= k ; i ++ ) Q.push( 0 );
		for( int i = 1 ; i <= n ; i ++ ){
			int u = Q.top(); Q.pop();
			Q.push( u + w[i] );
		}
		printf("%lld\n",Q.top());
		return 0;
	}
	init( 0 , 0 );
	for( int i = 1 ; i <= n ; i ++ ){
		int now = getmin( 0 );
		while( now ){
			val[now] += w[i];
			int minn = INF;
			for( int v : E[Fa[now]] ){
				minn = min( minn , dp[v] + val[v] );
			}
			dp[Fa[now]] = minn,now = Fa[now];
		}
	}
	printf("%lld\n",dp[0]);
	return 0;
}