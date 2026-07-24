#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 400005
int n,c,x[MAXN];

signed main(){
	scanf("%lld%lld",&n,&c);
	int m1 = -(int)1e18,m2 = -(int)1e18;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&x[i]);
		m1 = max( m1 , c * i - x[i] );
		m2 = max( m2 , c * i + x[i] );
		printf("%lld ",-c * i + max( m1 + x[i] , m2 - x[i] ));
	}
	return 0;
}