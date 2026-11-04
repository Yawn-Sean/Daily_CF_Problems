#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

int n;

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

//经典传统模型

signed main(){
	scanf("%d",&n); n -= 2;
	if( n <= 1 ) puts("1");
	else if( n <= 4 ) printf("%d\n",n);
	else{
		if( n % 3 == 2 ){
			printf("%lld\n",2ll * fp( 3 , n / 3 ) % mod);
		}
		else if( n % 3 == 1 ){
			printf("%lld\n",4ll * fp( 3 , n / 3 - 1 ) % mod);
		}
		else
			printf("%lld\n",fp( 3 , n / 3 ));
	}
	return 0;
}