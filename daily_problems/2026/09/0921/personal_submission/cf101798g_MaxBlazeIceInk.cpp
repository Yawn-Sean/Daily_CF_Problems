#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,a[MAXN],s[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	sort( a + 1 , a + n + 1 );
	for( int i = 1 ; i <= n ; i ++ ) s[i] = s[i - 1] + a[i];
	int L = n / 2,ans = 0;
	//手模一下样例即可
	while( L ){
		ans += s[n] - s[n - L] - ( s[n - L] - s[n - 2 * L] );
		L /= 2;
	}
	printf("%lld\n",ans);
	return 0;
}