#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,ca,cb,a[MAXN],b[MAXN],pos[MAXN],pre[MAXN];

inline void solve(){
	scanf("%lld%lld%lld",&n,&ca,&cb);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),pos[a[i]] = i;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]);
	pre[1] = pos[1];
	for( int i = 3 ; i <= 2 * n ; i += 2 ) pre[i] = min( pre[i - 2] , pos[i] );
	int ans = (int)1e18;
	for( int i = 1 ; i <= n ; i ++ ){
		ans = min( ans , ( i - 1 ) * cb + ( pre[b[i] - 1] - 1 ) * ca );
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}