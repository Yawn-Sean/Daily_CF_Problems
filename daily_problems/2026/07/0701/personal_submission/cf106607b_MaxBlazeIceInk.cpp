#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define MAXN 600005

int n,a[MAXN];

inline void solve(){
	scanf("%lld",&n);
	int S = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),S += a[i];
	if( S == n ){ puts("0"); return; }
	int l = 1,r = n;
	while( a[l] == 1 ) l ++;
	while( a[r] == 1 ) r --;
	for( int k = l ; k < r ; k ++ ){
		if( a[k] != a[k + 1] ){ puts("2"); return; }
	}
	puts("1");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}