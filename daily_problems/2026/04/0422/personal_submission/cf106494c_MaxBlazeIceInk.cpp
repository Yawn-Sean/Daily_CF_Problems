#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define int long long

int n,a[MAXN],s[MAXN];

inline int judge( int r , int x ){
	if( ( r + x ) % 2 ){
		return a[( r + x ) / 2 + 1];
	}
	else{
		return a[( r + x ) / 2 + 1];
	}
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	priority_queue< int , vector<int> , greater<int> > Q;
	priority_queue<int> Q2;
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) if( a[i] < 0 ) Q.push( a[i] ); else Q2.push( a[i] );
	while( !Q.empty() && !Q2.empty() )
		ans += Q2.top(),Q.pop(),Q2.pop();
	if( !Q.empty() ){
		int t = Q.size() / 2;
		while( t -- ) Q.pop();
		ans += Q.top();
	}
	else{
		while( !Q2.empty() ) ans += Q2.top(),Q2.pop();
	}
	printf("%lld\n",ans);
	return 0;
}