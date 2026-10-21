#include<bits/stdc++.h>
using namespace std;

//先做个 bitset 背包然后自下而上贪心就可以了

#define int long long
#define MAXN 100005

int n,q,a[MAXN],val[MAXN],ans,flg = 1;
vector<int> E[MAXN],res;

void dfs( int x , int fa ){
	int maxx = a[x];
	for( int v : E[x] ){
		if( v == fa ) continue;
		dfs( v , x );
		maxx = max( maxx , val[v] );
	}
	int d = maxx - a[x];
	int id = lower_bound( res.begin() , res.end() , d ) - res.begin();
	if( id == res.size() ) flg = 0;
	else{
		val[x] = a[x] + res[id];
	}
}

signed main(){
	scanf("%lld%lld",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	bitset<1000005> B; B[0] = 1;
	for( int i = 1 ; i <= q ; i ++ ){
		int x; scanf("%lld",&x);
		B |= B << x;
	}
	for( int i = 0 ; i <= (int)1e6 ; i ++ )
		if( B[i] ) res.emplace_back( i );
	dfs( 1 , 0 );
	if( !flg ){ puts("-1"); return 0; }
	for( int i = 1 ; i <= n ; i ++ ) ans += val[i];
	printf("%lld\n",ans);
	return 0;
}