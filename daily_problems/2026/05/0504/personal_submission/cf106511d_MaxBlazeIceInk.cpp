#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;

int t[9] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};

signed main(){
	scanf("%lld",&n);
	int ans = 0;
	for( int i = 1 ; i <= 9 ; i ++ ){
		int c = 0;
		for( int j = 0 ; j < 9 ; j ++ )
			if( n >= 1ll * t[j] * i ) ans ++;
		// cerr << ans << "\n";
	}
	for( int j = 1 ; j < 9 ; j ++ ) ans += n >= t[j] - 1;
	printf("%lld\n",ans + ( n == (int)1e9 ));
	return 0;
}