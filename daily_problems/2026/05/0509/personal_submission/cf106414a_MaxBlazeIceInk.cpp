#include<bits/stdc++.h>
using namespace std;

inline void solve(){
	int n,m,R1,C1,R2,C2;
	scanf("%d%d%d%d%d%d",&n,&m,&R1,&C1,&R2,&C2);
	int d1 = abs( R1 - R2 ),d2 = abs( C1 - C2 );
	int ans = 2;
	if( d1 == 0 ) ans --;
	else if( d1 % 2 == 0 ) ans ++;
	if( d2 == 0 ) ans --;
	else if( d2 % 2 == 0 ) ans ++;
	printf("%d\n",ans);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}