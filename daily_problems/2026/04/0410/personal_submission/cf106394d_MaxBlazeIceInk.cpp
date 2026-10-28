#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,a[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int now = 0,maxx = 0,ans = 0;
	for( int i = 1 ; i < n ; i ++ ){
		maxx = max( maxx , a[i] );
		if( now == 0 ) now += maxx,ans ++;
		now --,ans ++;
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}