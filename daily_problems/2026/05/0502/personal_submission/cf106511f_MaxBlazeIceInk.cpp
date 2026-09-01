#include<bits/stdc++.h>
using namespace std;

int n,m;

inline void solve(){
	scanf("%d%d",&n,&m);
	if( n > m ) swap( n , m );
	if( m == 1 ) puts("1");
	else if( n == 1 ) puts("2");
	else if( n == m ) puts("8");
	else puts("4");
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}