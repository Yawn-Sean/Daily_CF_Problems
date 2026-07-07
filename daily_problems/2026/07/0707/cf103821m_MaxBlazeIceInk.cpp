#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005
#define mod 1000000007

int n,a[MAXN],pos[MAXN],fac[MAXN],d[MAXN];

inline void solve(){
	scanf("%lld",&n);
	printf("%lld\n",( d[n] - n ) * fac[n] % mod * 500000004 % mod);
}

signed main(){
	fac[0] = 1;
	for( int i = 1 ; i < MAXN ; i ++ )
		for( int j = i ; j < MAXN ; j += i ) d[j] ++;
	for( int i = 1 ; i < MAXN ; i ++ ) d[i] += d[i - 1];
	for( int i = 1 ; i < MAXN ; i ++ ) fac[i] = fac[i - 1] * i % mod;
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}