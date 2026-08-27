#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,r[MAXN],c[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&r[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&c[i]);
	int ans = min( r[1] + c[n] , r[n] + c[1] );
	for( int i = 1 ; i <= n ; i ++ ){
		ans = min( ans , r[1] + r[n] + c[i] );
		ans = min( ans , c[1] + c[n] + r[i] );
	}
	//缺一个 case：不选任何列/行
	int ans1 = 0,ans2 = 0;
	for( int i = 1 ; i <= n ; i ++ ) ans1 += r[i],ans2 += c[i];
	ans = min( ans , min( ans1 , ans2 ) );
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}