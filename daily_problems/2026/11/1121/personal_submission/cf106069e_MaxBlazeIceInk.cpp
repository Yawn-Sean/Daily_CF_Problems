#include<bits/stdc++.h>
using namespace std;

#define int long long

int x,y,n;

inline void solve(){
	scanf("%lld%lld%lld",&x,&y,&n);
	y %= n;
	int A = y,B = n - y;
	if( !A ){
		if( x % n == 0 ) puts("0");
		else puts("1");
	}
	else
	if( x < 2 * B ){
		if( x >= B ) puts("1");
		else puts("2");
	}
	else if( x == 2 * B ) puts("0");
	else{
		x -= 2 * B;
		if( x % n == 0 ) puts("0");
		else puts("1");
	}
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}