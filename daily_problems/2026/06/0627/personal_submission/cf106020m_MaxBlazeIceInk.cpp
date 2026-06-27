#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,a[MAXN];

inline void solve(){
	scanf("%lld",&n);
	int S = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),S += a[i];
	if( n == 1 ){ printf("%lld\n",a[1]); return; }
	int ans = S; ans ^= S - a[1]; ans ^= S - a[n]; ans ^= S - a[1] - a[n];
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}