#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;

signed main(){
	scanf("%lld%lld",&n,&m);
	int ans = 0;
	for( int g1 = 1 ; g1 < n ; g1 ++ ){
		for( int g2 = 1 ; g2 < m ; g2 ++ ){
			if( gcd( g1 , g2 ) == 1 ){
				int A = n - g1,B = m - g2;
				ans += A * B - max( 0ll , A - g1 ) * max( 0ll , B - g2 );
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}