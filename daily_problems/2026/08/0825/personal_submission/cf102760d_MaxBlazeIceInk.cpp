#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
int n,a[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n * ( n - 1 ) / 2 ; i ++ ) scanf("%lld",&a[i]);
	sort( a + 1 , a + n * ( n - 1 ) / 2 + 1 );
	int ans = 0;
	for( int i = 1 ; i < n ; i ++ ) ans += a[i];
	int now = 1,res = 0;
	for( int i = 1 ; i < n ; i ++ ){
		res += a[now],now += i;
	}
	printf("%lld %lld\n",ans,res);
	return 0;
}