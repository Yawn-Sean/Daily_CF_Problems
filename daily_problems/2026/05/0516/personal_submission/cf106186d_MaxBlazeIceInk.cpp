#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
#define mod 1000000007

int n,a[MAXN],b[MAXN],cnt[2][MAXN],f[2][MAXN],g[MAXN],vis[MAXN],isp[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),cnt[0][a[i]] ++;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]),cnt[1][b[i]] ++;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; i * j <= n ; j ++ )
			f[0][i] += cnt[0][i * j],f[1][i] += cnt[1][i * j];
	for( int i = 1 ; i <= n ; i ++ )
		g[i] = f[0][i] * f[1][i];
	for( int i = n ; i >= 1 ; i -- )
		for( int j = 2 ; i * j <= n ; j ++ ) g[i] -= g[i * j];
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) ans += isp[i] * g[i],cnt[0][i] = cnt[1][i] = f[0][i] = f[1][i] = g[i] = 0;
	printf("%lld\n",ans);
}

signed main(){
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( vis[i] ) continue;
		isp[i] = 1;
		for( int j = 1 ; i * j < MAXN ; j ++ ) vis[i * j] = 1;
	}
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}