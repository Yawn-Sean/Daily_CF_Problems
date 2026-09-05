#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;

signed main(){
	scanf("%lld",&n);
	int ans = 1;
	for( int i = n ; i >= 1 ; i -- ){
		int L = max( 2 * i , n + 1 );
		int c = 2 * n - L + 1;
		int t = n - i;
		ans *= ( c - t );
	}
	printf("%lld\n",ans);
	return 0;
}