#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define int long long

int n,k,b[MAXN],w[MAXN],v[MAXN],dif[MAXN];

signed main(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&w[i]);
		if( b[i] + w[i] > k ) continue;
		//b >= b[i],b <= k - w[i]
	}
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&v[i]);
		int L = b[i],R = k - w[i];
		if( L <= R ) dif[L] += v[i],dif[R + 1] -= v[i];
	}
	//简单差分即可
	int ans = 0;
	for( int i = 1 ; i <= k ; i ++ ) dif[i] += dif[i - 1],ans = max( ans , dif[i] );
	printf("%lld\n",ans);
	return 0;
}