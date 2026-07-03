#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m,k;

inline void solve(){
	scanf("%lld%lld%lld",&n,&m,&k);
	if( k < n ){
		printf("%lld\n",k);
		return;
	}
	if( m % 2 ){
		
			if( n % 2 == k % 2 ){ printf("%lld\n",n); return; }
		else printf("%lld\n",n - 1);
		return;
	}
	else{
		int lim = n * m - k;
		if( lim < n ) printf("%lld\n",lim);
		else{
			
			if( n % 2 == k % 2 ){ printf("%lld\n",n); return; }
			printf("%lld\n",n - 1);
		}
	}
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}