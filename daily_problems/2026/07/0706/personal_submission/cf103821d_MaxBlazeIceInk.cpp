#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n;

inline void solve(){
	scanf("%d",&n);
	int bas = sqrt( n + 1 );
	if( bas * bas != ( n + 1 ) ) puts("-1");
	else{
		printf("%d\n",bas - 1);
		for( int i = 1 ; i < bas ; i ++ ) printf("%d ",i);
		puts("");
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}