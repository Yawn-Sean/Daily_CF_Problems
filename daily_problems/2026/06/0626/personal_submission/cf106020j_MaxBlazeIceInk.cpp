#include<bits/stdc++.h>
using namespace std;

inline void solve(){
	int n,k; scanf("%d%d",&n,&k);
	if( n == 2 ){
		if( ( k & -k ) == k ) puts("1");
		else puts("0");
	}
	else{
		int v = k - n;
		if( n % 2 == 0 && k - n == n / 2 + 1 ) puts("1");
		else printf("%d\n",max( 0 , n - 1 - 2 * v ));
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}