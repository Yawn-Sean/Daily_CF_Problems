#include<bits/stdc++.h>
using namespace std;

#define MAXN 600005

int n,a[MAXN];

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	if( a[1] > 2 || a[n] > 2 ){ puts("NO"); }
	else puts("YES");
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}