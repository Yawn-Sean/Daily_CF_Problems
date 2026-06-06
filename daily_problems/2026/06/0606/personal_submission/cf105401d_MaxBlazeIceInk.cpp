#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
int n,a[MAXN];

signed main(){
	scanf("%lld",&n);
	a[1] = 1000000000,a[2] = a[1] + ( 2 * n + 1 );
	for( int i = 1 , p = 1 , q = 2 * n - 1 ; i <= n ; i ++ ){
		if( i & 1 ) a[i + 2] = a[i + 1] - p,p += 2;
		else a[i + 2] = a[i + 1] + q,q -= 2;
	}
	for( int i = 1 ; i <= n + 2 ; i ++ ) printf("%lld ",a[i]);
	puts("");
	return 0;
}