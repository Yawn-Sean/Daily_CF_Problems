#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,c,a[MAXN];

//随便贪心一下

signed main(){
	scanf("%lld%lld",&n,&c);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	int ans = 0;
	for( int i = n , rem = 0 ; i >= 1 ; i -- ){
		int t = min( a[i] , rem );
		a[i] -= t,rem -= t;
		ans += ( a[i] + c - 1 ) / c * i;
		a[i] %= c;
		if( a[i] ) rem += c - a[i];
	}
	printf("%lld\n",2 * ans);
	return 0;
}