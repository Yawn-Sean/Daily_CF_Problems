#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,s[MAXN],v[MAXN],maxx[MAXN],f[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld",&s[i],&v[i]);
		maxx[s[i]] = max( maxx[s[i]] , v[i] );
	}
	for( int i = 1 ; i <= 1000000 ; i ++ ){
		if( !maxx[i] ) continue;
		if( maxx[i] <= f[i] ) continue;
		for( int j = 0 ; j + i <= 1000000 ; j ++ ){
			f[j + i] = max( f[j + i] , f[j] + maxx[i] );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",f[i]);
	return 0;
}