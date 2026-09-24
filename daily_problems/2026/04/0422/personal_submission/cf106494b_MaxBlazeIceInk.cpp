#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define MAXN 200005

int n,l[MAXN],r[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&l[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&r[i]);
	int pid = 0;
	for( int i = 1 ; i <= n ; i ++ )
		if( !pid || l[i] > l[pid] ) pid = i;
	int S = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( i == pid ) continue;
		S += min( r[i] , l[pid] );
	}
	// cerr << pid << "\n";
	if( l[pid] > S ){ puts("-1"); return 0; }
	for( int i = 1 ; i <= n ; i ++ ){
		if( i == pid ) printf("%lld ",l[pid]);
		else printf("%lld ",min( r[i] , l[pid] ));
	}
	return 0;
}