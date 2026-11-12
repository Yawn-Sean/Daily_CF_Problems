//a[u] 的首个 1 在 a[v] 的 1 上
//a[v] 的首个 1 更高

//可以优化建图

#include<bits/stdc++.h>

using namespace std;

#define MAXN 300005
#define int long long

int n,a[MAXN],dp[MAXN],id[62],deg[MAXN];
vector<int> E[MAXN];

inline void solve(){
	scanf("%lld",&n);
	int nodecnt = 60;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&a[i]);
		++nodecnt;
		if( !a[i] ) continue;
		int hib = 61; while( !( a[i] >> hib & 1 ) ) hib --;
		E[hib].emplace_back( nodecnt );
		for( int j = 0 ; j < hib ; j ++ ) if( a[i] >> j & 1 ) E[nodecnt].emplace_back( j );
	}
	for( int i = 0 ; i <= nodecnt ; i ++ )
		for( int ele : E[i] ){
			deg[ele] ++;
			// cerr << i << " " << ele << "\n"; 
		}
	queue<int> Q;
	for( int i = 0 ; i <= nodecnt ; i ++ ) if( !deg[i] ) Q.push( i ),dp[i] = i > 60;
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		for( int v : E[u] ){
			dp[v] = max( dp[v] , dp[u] + ( v > 60 ) );
			if( !--deg[v] ) Q.push( v );
		}
	}
	int ans = 0;
	for( int i = 0 ; i <= nodecnt ; i ++ ) ans = max( ans , dp[i] ),E[i].clear(),deg[i] = dp[i] = 0;
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}