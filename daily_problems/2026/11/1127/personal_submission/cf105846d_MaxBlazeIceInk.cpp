#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
#define MAXN 1000005

int n,p[MAXN],fac[MAXN];

inline void solve(){
	scanf("%d",&n);
	if( n == 1 ){ puts("0"); return; }
	else if( n % 2 == 0 ){ puts("1"); return; }
	//n = 3 -> 3 3
	//n = 5 -> 15 5
	//每行每列都恰好一个 1 一个 2
	//答案是错排
	printf("%d\n",1ll * fac[n] * p[n] % mod);
}

/*
*....
.*...
..*..
...*.
....*

*/

signed main(){
	fac[0] = 1;
	p[2] = 1;
	for( int i = 3 ; i < MAXN ; i ++ ) p[i] = 1ll * ( i - 1 ) * ( p[i - 1] + p[i - 2] ) % mod;
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}