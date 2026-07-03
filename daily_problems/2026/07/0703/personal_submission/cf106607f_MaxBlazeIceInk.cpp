#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
int n,m;

inline int fp( int x , int p ){
	x %= mod;
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void solve(){
	scanf("%lld%lld",&n,&m); m ++;
	//每一位是几乎独立的
	//考虑 significant bit
	int Ans = 0,res = 1;
	for( int i = 60 ; i >= 0 ; i -- ){
		if( !( m >> i & 1 ) ) continue;
		//钦定这一位为 0，则上面所有 bit 都需一致
		Ans += fp( n + 1 , i ) * res % mod;
		Ans %= mod;
		res = res * ( n % mod ) % mod;
	}
	printf("%lld\n",Ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}