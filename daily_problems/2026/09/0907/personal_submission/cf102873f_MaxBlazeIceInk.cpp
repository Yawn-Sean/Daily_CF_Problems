#include<bits/stdc++.h>
using namespace std;

int n;

inline void solve(){
	scanf("%d",&n);
	//猛猛猜
	if( n % 2 ) puts("Bob");
	else if( n % 4 == 2 ) puts("Alice");
	else puts("Draw");
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}