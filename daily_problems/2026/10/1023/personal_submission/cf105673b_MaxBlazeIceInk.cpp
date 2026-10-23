#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define int long long
#define INF (int)1e18
int n,k,a[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int ans = -INF;
	for( int i = 1 ; i <= n ; i ++ ){
		int res = 0,p = 0;
		for( int j = i , now = 1 ; j <= n ; j += now , now ++ ){
			res += a[j];
			if( res < -k ) break;
			p = max( p , res );
		}
		ans = max( ans , p );
	}
	printf("%lld\n",ans + k);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}