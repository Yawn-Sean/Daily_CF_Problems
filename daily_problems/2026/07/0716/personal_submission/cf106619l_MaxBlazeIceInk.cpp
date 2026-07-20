#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 300005

int n,k,a[MAXN];

inline void solve(){
	scanf("%lld%lld",&n,&k);
	multiset<int> S;
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ){
		ans += a[i];
		if( !S.size() || a[i] > *S.rbegin() ) S.insert( a[i] );
		else{
			S.erase( S.lower_bound( a[i] ) );
			S.insert( a[i] );
		}
		int L = S.size();
		// cerr << i << " " << L << " " << *S.rbegin() << "\n";
		if( L > *S.rbegin() ){
			//L,L+1,L+2,...,L+k-1;
			int res = ans + L * k + k * ( k - 1 ) /2 ;
			printf("%lld ",res);
		}
		else{
			int res = ans + L * k;
			printf("%lld ",res);
		}
	}
	puts("");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}