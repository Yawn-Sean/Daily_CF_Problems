#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,a[MAXN],f[MAXN],pre[MAXN];

inline void solve(){
	scanf("%lld",&n);
	printf("%lld\n",f[n] % 1000000007);
}

signed main(){
	//1 1 4 4 9 9
	for( int i = 3 ; i < MAXN ; i ++ )
		f[i] = f[i - 1] + ( ( i - 1 ) / 2 ) * ( ( i - 1 ) / 2 );
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}