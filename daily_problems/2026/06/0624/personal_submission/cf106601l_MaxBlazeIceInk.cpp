#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X;

signed main(){
	scanf("%lld",&X);
	ll B = 1,ans = 0; while( B * B <= X ) B ++; B --;
	for( int i = 2 ; i <= B ; i ++ ){
		ll tmp = X,res = 0;
		while( tmp ) res ^= tmp % i,tmp /= i;
		if( !res ) ans ++;
	}
	// cerr << ans << "\n";
	//(b + 1)i = X -> b >= B
	for( ll i = 1 ; i * i <= X ; i ++ ){
		if( X % i == 0 ){
			ll b = X / i;
			if( b - 1 > B && b - 1 <= X ) ans ++;
			b = i;
			if( b != X / i && b - 1 > B && b - 1 <= X ) ans ++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

/*
2 
3 
4 
16 
33 
67 
*/